FROM frolvlad/alpine-gxx

WORKDIR /usr/src/myapp

COPY . .

RUN apk update

RUN apk add --no-cache git

RUN c++ --static -o myapp main.cpp

CMD ["./myapp"]