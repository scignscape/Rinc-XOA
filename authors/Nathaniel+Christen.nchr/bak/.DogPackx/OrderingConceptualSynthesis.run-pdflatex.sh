pdfl=~/texlive/bin/x86_64-linux/pdflatex
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  \
  -jobname=OrderingConceptualSynthesis OrderingConceptualSynthesis.gt.tex
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  \
  -jobname=OrderingConceptualSynthesis.sdi \
  "\def\SdiShowFlag{1} \input{OrderingConceptualSynthesis.gt.tex}"
