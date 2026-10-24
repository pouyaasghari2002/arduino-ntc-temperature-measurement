# Build the English report

Upload the complete project ZIP to Overleaf using New Project → Upload Project. Select `report/main.tex` as the main document and use pdfLaTeX. If the outer project folder is retained, include it in the selected path.

Keep the original sibling `arduino/` and `matlab/` folders. The report imports code listings from both; uploading only `main.tex` and figures will not be sufficient.

For a local TeX Live or MiKTeX installation, run these commands from the repository root:

```bash
cd report
pdflatex -interaction=nonstopmode -halt-on-error main.tex
pdflatex -interaction=nonstopmode -halt-on-error main.tex
```

The second pass resolves the contents and bookmarks. The report uses standard packages and Latin Modern fonts; no custom font, `.bib`, `.cls`, or `.sty` files are required. Typesetting does not execute the code or validate the circuit.
