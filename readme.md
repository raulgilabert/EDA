# EDA

## Profesor

Conrado Martínez conrado@cs.upc.edu

## Ponderación notas

## STL

STL es la biblioteca estándar del lenguaje pero no es parte de esta por defecto. Cada compilador tiene su propia implementación de la STL en base a la definición estándar del lenguaje.

Desde C++11 se han introducido otro tipo de recorrer vectores:

```C++
vector<string> words;

...

for (string w : words) {
  cout << ' ' << w;
}
```

También se ha añadido la palabra clave `auto` que se puede usar para sustituir por un tipo deducido por el compilador, reduciendo en tamaño iteraciones en clases de la STL con iteradores:

```C++
// auto => list<string>::const_iterator
for (auto it = L.begin(); it != L.end(); ++i) {
  v[k] = *it;
  ++k;
}
```

Y esto juntado con la nueva iteración en vectores:

```C++
for (auto w : words) {
  ...
}
```

## Priority queue

Los elementos son añadidos a la cola en base a una prioridad y no en base al orden de entrada. Técnicamente no es un contenedor, sino que es un adaptador construido por encima de un contenedor con iteradores de acceso aleatorio, por ejemplo un vector.
