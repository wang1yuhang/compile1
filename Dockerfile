FROM alpine:3
RUN apk add cmake gcc g++ libgcc build-base make --no-cache
WORKDIR /app/
COPY ./* ./
RUN g++ main1.cpp -o main1
RUN chmod +x main1
