#!/usr/bin/env python3

import argparse
import re
import requests


def strip_tag(s):
    return re.sub(r'<.*?>', '', s)


def read_table(table_str, filterfun=int):
    table = {}
    for i, tr in enumerate(re.finditer(r'<tr[^>]*>(.*?)</tr>', table_str, re.M | re.S | re.I)):
        line = []
        for td in re.finditer(r'<td[^>]*>(.*?)</td>', tr.group(1), re.M | re.S | re.I):
            line.append(strip_tag(td.group(1)))
        if i == 0:
            header = line
        else:
            if len(header) != len(line):
                print("Número de colunas não bate ao ler tabela! Ignorando linha...")
                continue
            item = {k: v for k, v in zip(header, line)}
            try:
                lk = filterfun(item[header[0]])
            except:
                lk = item[header[0]]
            table[lk] = item

    return table

# tenta ler os dados de uma tabela do google
# com a primeira tabela contendo uma coluna de título ra com todos os
# ras dos alunos
def read_google_tables(url, nontables, filterfun=int):
    r = requests.get(url)
    if r.status_code != 200:
        raise Exception('Erro ao ler do google: ' + str(r.status_code) + ' , ' + r.reason)


    # encontra titulos

    m = re.search(r'<ul.*?sheet-menu.*?>.*?</ul>', r.text, re.M | re.S)
    titles = [strip_tag(u.group(1)) for u in re.finditer(r'<li[^>]*>(.*?)</li>', m.group(0), re.M | re.S)]
    # sheetids = [u.group(1) for u in re.finditer(r'switchToSheet\(\'(.*?)\'\);', m.group(0), re.M | re.S)]
    tables = {}
    for nt in nontables:
        titles.remove(nt)
    for title, body in zip(titles, re.finditer(r'<tbody[^>]*>(.*?)</tbody>', r.text, re.M | re.S)):
        tables[title] = read_table(body.group(1), filterfun)

    return tables



# tenta ler os dados de submissão do susy
# com a primeira tabela contendo uma coluna de título ra com todos os
# ras dos alunos

import urllib3
urllib3.disable_warnings()

def read_susy_tables(exercicio, turma, filterfun=int):
    url = r'https://susy.ic.unicamp.br:9999/mc202efgh/{}/relato{}.html'.format(exercicio, turma)
    r = requests.get(url, verify=False)
    if r.status_code != 200:
        raise Exception('Erro ao ler do susy: ' + str(r.status_code) + ' , ' + r.reason)

    m = re.search(r'<table[^>]*>(.*?)</table>', r.text, re.M | re.S | re.I)
    if not m:
        return []
    return read_table(m.group(1), filterfun)

def main():
    dados = {
        'disciplina': 'mc202efgh',
        'exercicios': [ '01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13', '14', '15'],
        'turmas': [
            {
                'codigo': 'GH',
                'google_url' : 'https://docs.google.com/spreadsheets/d/e/2PACX-1vQOkeDIJw3oDz0i5vf4kb-qkvJf4rb87LfWmCeNi3arEgwz2-Ca8ln_Fum4QO5N_nkXA4yIkpiImSL7/pubhtml',
                # verifica se coluna desse indice está vazio na planilha do google
                'entregas_cols': [
                    ('ENTREGA-{}', 'casos de teste'),
                    ('FORAPRAZO-{}', 'FP: comentários'),
                ],
                'nontables' : [],
            },
            {
                'codigo': 'EF',
                'google_url' : 'https://docs.google.com/spreadsheets/d/e/2PACX-1vS-VSRJILSrkE-vB26azoRYdo6vntNEZ1KgFxt2y6uuvIMaM8GnmYsb8ES8G_XnhROKsFgxa9qwFdsU/pubhtml',
                # verifica se coluna desse indice está vazio na planilha do google
                'entregas_cols': [
                    ('ENTREGA-{}', 'comentários'),
                    ('FORAPRAZO-{}', 'FP: comentários'),
                ],
                'nontables' : ['Aprovação'],
            },
        ]
    }

    # parser = argparse.ArgumentParser(description='Verifica se há submisão não corrigidsa.',
    #                                  formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    # args = parser.parse_args()

    for t in dados['turmas']:
        tcod = t['codigo']
        print("\nPROCESSANDO TURMA {}:".format(tcod))
        notas = read_google_tables(t['google_url'], t['nontables'])
        print(" ".join(notas.keys()))
        for exerc in dados['exercicios']:
            for entrega, col in t['entregas_cols']:
                lab = entrega.format(exerc)
                print("{}:".format(lab))
                susy = read_susy_tables(lab, tcod)
                if not susy:
                    print("não encontrou relatório no susy")
                else:
                    corrigidos = []
                    aba = 'L{}'.format(int(exerc))
                    if aba not in notas or not notas[aba]:
                        print('aba {} não encontrada na planilha de notas ou aba vazia'.format(aba))
                    elif col not in notas[aba][next(iter(notas[aba]))]:
                        print("coluna {} não está na aba {} da planilha de notas; supondo que não corrigiu de nenhum aluno".format(col, aba))
                    else:
                        corrigidos = [id for id in notas[aba] if notas[aba][id][col].strip() != '']
                    nao_corrigidos = [str(k) for k in susy if int(k) not in corrigidos]
                    print("corrigidos {}   faltam {}\n{}".format(len(corrigidos), len(nao_corrigidos), "\n".join(nao_corrigidos)))
                print()

main()
