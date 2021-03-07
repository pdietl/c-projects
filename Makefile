SOURCES := $(shell find . -name '*.tex')
TARGETS := $(patsubst %.tex,%.pdf,$(SOURCES))

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
	$(RM) $(@:.pdf=.aux) $(@:.pdf=.log)
