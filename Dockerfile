FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get -y upgrade

# This takes forever, so separate it out
RUN apt-get -y install texlive-latex-extra

RUN apt-get -y install \
    make \
    vim

ADD hyperlatex.sty /usr/share/texmf/tex/latex/misc/

RUN texhash
