FROM ubuntu:16.04
WORKDIR /app/
COPY ./* ./
RUN apt update && apt-get install g++ cmake gcc libgcc build-base make
RUN g++ my-program.cpp -o program 
RUN chmod +x program
