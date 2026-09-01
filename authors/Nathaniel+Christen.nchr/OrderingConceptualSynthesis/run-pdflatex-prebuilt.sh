pdfl=/home/nlevisrael/texlive/bin/x86_64-linux/pdflatex
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  prebuilt.gt.tex
