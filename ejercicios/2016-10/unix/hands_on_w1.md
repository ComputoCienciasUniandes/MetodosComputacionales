# Hands-on 1
21-01-2016

- Traer el archivo   http://www.finiterank.com/saber/2011.csv
- Traer el archivo https://raw.github.com/forero/ComputationalPhysicsUniandes/master/hands_on/unix/columnas_2011.csv.txt
- Utilizar el siguiente comando para seleccionar una columna del archivo 2011.csv

```sh
$   awk -F "\"*,\"*" '{print $3}' file.csv
```

- Cuantos colegios publicos hay?
- Cuantos colegios privados hay?
- Cuantos colegios privados de calendario A hay?
- Cuantos colegios privados de calendario B hay?
- Cuantos colegios publicos de calendario B hay?
- Prepare archivos separados para colegios publicos y privados por separado que incluyan las siguientes columnas:
  Promedio Total, Nota Matematica, Nota Ingles
- Grafique Promedio Total vs Nota Matematica en los dos tipos de colegios.
- Grafique Promedio Total vs Nota Ingles en los dos tipos de colegios.

AGRADECIMIENTOS: A Javier Moreno por haber compilado estos datos http://nbviewer.ipython.org/url/finiterank.com/saber/saber.ipynb

