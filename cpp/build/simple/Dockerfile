FROM gcc

ONBUILD ENV output_dir=/usr/bin/app
ONBUILD ENV app=${output_dir}/app
ONBUILD WORKDIR /usr/src/app .
ONBUILD COPY . .
ONBUILD RUN mkdir --parents ${output_dir}
ONBUILD RUN g++ *.cpp -o ${app} -static -static-libgcc -static-libstdc++
