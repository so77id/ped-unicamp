search_dir=testes_fechados

for fullfile in "../$search_dir"/*
do
  filename=$(basename -- "$fullfile")
  extension="${filename##*.}"
  name="${filename%.*}"
  echo "executing: $fullfile"
  cd /usr/src/myapp/lab04

  ./lab04 < ${search_dir}/${filename} > ${search_dir}/${name}.res

done
