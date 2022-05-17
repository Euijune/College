FROM ubuntu:14.04
MAINTAINER Dr.Sungwon "drsungwon@khu.ac.kr"
RUN apt-get update
RUN apt-get install -y nginx
RUN echo "this is a ubuntu container"
WORKDIR /etc/nginx
CMD ["nginx", "-g", "daemon off;"]
EXPOSE 80