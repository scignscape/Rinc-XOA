pdfl=~/texlive/bin/x86_64-linux/pdflatex
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  \
  -jobname=i gen.tex

#pdf2svg out/i.pdf i-from-pdf.svg
pdftocairo -svg out/i.pdf i-from-pdf.svg 
