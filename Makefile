SOURCES := $(shell find . -name '*.tex')
TARGETS := $(patsubst %.tex,%.pdf,$(SOURCES))

DOCKER_IMG_TAG := c-projects

DOCKER_CMD := docker run -ti --rm -v /etc/group:/etc/group:ro -v /etc/passwd:/etc/passwd:ro -u $$(id -u):$$(id -g) -v$(CURDIR):$(CURDIR) -w $(CURDIR) $(DOCKER_IMG_TAG)

define NL :=


endef

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	$(foreach f, $(TARGETS), \
		$(RM) $(f)$(NL))

%.pdf: %.tex
	cd $(@D) && pdflatex $(<F) > /dev/null
	@$(RM) $(@:.pdf=.aux) $(@:.pdf=.log)

docker: Dockerfile hyperlatex.sty
	docker build . --tag $(DOCKER_IMG_TAG)

docker-shell:
	$(DOCKER_CMD) /bin/bash

docker-%:
	$(DOCKER_CMD) make $(MAKEFLAGS) $*
