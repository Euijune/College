#FROM ubuntu:latest
#MAINTAINER euijune "choah76@khu.ac.kr"

#RUN apt-get update \
#  && apt-get install -y python3-pip python3-dev \
#  && cd /usr/local/bin \
#  && ln -s /usr/bin/python3 python \
#  && pip3 install --upgrade pip

#ENTRYPOINT [ "python3" ]

FROM ubuntu:14.04
MAINTAINER euijune "choah76@khu.ac.kr"

RUN apt-get update
RUN apt-get install -y nginx
RUN echo "this is a ubuntu container"

WORKDIR /etc/nginx

CMD ["nginx","-g","daemon off;"]
EXPOSE 80