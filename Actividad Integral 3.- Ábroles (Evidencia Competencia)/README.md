# Actividad Integral 3
## Marco contextual 
Dentro del videojuego de Pokemon existe una herramienta muy famosa y muy util llamada la Pokedex. Una Pokedex es una enciclopedia portátil de alta tecnología que los Entrenadores Pokémon llevan consigo para registrar las fichas de todas las diversas especies Pokémon con las que se encuentran durante su viaje. La pokedex registra los datos generales de los pokemones tales como el nombre, numero de pokemon, peso, altura, tipo de pokemon, etc.
## Funcionamiento
El programa  es una simulacion de una Pokedex, este utiliza informacion almacenada en un archivo de texto que contiene unicamente los primeros 151 (por el momento limitado a los primeros 20) pokemones con su normbre, numero de pokemon, tipo de pokemon, altura y peso. Mediante este archivo de texto y con ayuda de estructura de datos el usuario puede hacer organizar la lista por atributos o hacer busquedas especificas por medio de el tipo de pokemon. Estos ordenamientos y busquedas seran registrados y podran ser consultadas por el usuario en un archivo de texto llamado "datos_pokedex.txt" por medio del siguiente formato:

**---------------------------**

No. 1 Bulbasaur

Type ................ Planta
    
Weight .......... 6.9 Kg

Height .......... 0.7 Mts

**---------------------------**

## Análisis de complejidad temporal

### bubbleNumero()

Basado en el bubble sort. Funciona revisando cada numero de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado, en este caso en de orden decendente a acendente. Cada pasada a lo largo de la lista ubica el siguiente valor más grande en su lugar apropiado. Su complejidad temporal es O(n^2) para el peor de los casos.

### bubbleNombre()

Basado en el bubble sort. Funciona revisando cada nombre de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado, en este caso en orden alfabetico. Cada pasada a lo largo de la lista ubica cada nombre en su lugar apropiado. Su complejidad temporal es O(n^2) para el peor de los casos.

### bubbleTipo()

Basado en el bubble sort. Funciona revisando cada tipo de pokemon de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado, en este caso en orden alfabetico. Cada pasada a lo largo de la lista ubica el siguiente tipo de pokemon en su lugar apropiado. Su complejidad temporal es O(n^2) para el peor de los casos.

### bubbleAltura()

Basado en el bubble sort. Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado, en este caso en de orden decendente a acendente. Cada pasada a lo largo de la lista ubica el siguiente valor de altura más grande en su lugar apropiado. Su complejidad temporal es O(n^2) para el peor de los casos.

### bubblePeso()

Basado en el bubble sort. Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado, en este caso en de orden decendente a acendente. Cada pasada a lo largo de la lista ubica el siguiente valor de paso más grande en su lugar apropiado. Su complejidad temporal es O(n^2) para el peor de los casos.

### busq()

Basado en la busqueda secuencial. Consiste en una busqueda comenzando en el primer ítem de la lista, simplemente nos trasladamos de un numero a otro, siguiendo el orden secuencial subyacente hasta que encontremos lo que buscamos o nos quedemos sin items. Su complejidad temporal es O(n) para el peor de los casos.

### add()

El algoritmo seía O(n) en el peor de los casos. El algoritmo recorrera una lista hasta llegar al ultimo elemnto por medio de un ciclo while y añadira un indice mas.Por lo mismo seria O(n) ya que se recorre n elementos de la lista en el peor de los casos. Igualmente se tiene un addFirst que añadira un valor como primer elemento de la lista. Este tendra una complejidad de O(1).

### push()

El algoritmo agrega un nuevo elemento al arbol, este lo hace en orden en especifico que es de derecha a izquierda y por niveles de forma acendente a decendente empezando por la raiz. Igualmente el heap nos dice que el padre debe de ser menor a los hijos, de esta forma si el nuevo elemento es mayor a un padre se hara un swap. El nivel de complejidad seria de O(log n) para el peor de los casos.

### busqHeap()

Basado en la busqueda secuencial. Consiste en una busqueda comenzando en el primer ítem de la lista, simplemente nos trasladamos de un numero a otro, siguiendo el orden secuencial subyacente hasta que encontremos lo que buscamos o nos quedemos sin items. Su complejidad temporal es O(n) para el peor de los casos.

### toString()

El algoritmo recorre toda la informacion del arbol para almacenar un string por cada recorrido del ciclo. Ya que se reccore todo la informacion su analisis de complejidad seria de O(n).


## Casos de prueba

### Prueba 1:

Ordenar datos de pokedex por atributos -> Altura -> Resultado: 0.3 Mts, 0.3 Mts, 0.3 Mts, 0.3 Mts, 0.3 Mts, 0.5 Mts, 0.6 Mts, 0.7 Mts, 0.7 Mts, 0.7 Mts, 1 Mts, 1 Mts, 1 Mts, 1.1 Mts, 1.1 Mts, 1.1 Mts, 1.5 Mts, 1.6 Mts, 1.7 Mts, 2 Mts

### Prueba 2:

Ordenar datos de pokedex por atributos -> Nombre -> Resultado: Beedrill, Blastoise, Bulbasaur, Butterfree, Caterpie, Charizard, Charmander, Charmeleon, Ivysaur, Kakuna, Metapod, Pidgeot, Pidegeotto, Pidgey, Raticate, Rattata, Squirtle, Venasaur, Wartortle, Weedle

### Prueba 3:

Buscar objetos por tipo de Pokemon -> Fuego -> Resultado: Charmander, Carmeleon, Charizard

### Prueba 4:

Buscar objetos por tipo de Pokemon -> Hada -> Clefairy, Clefable

### Prueba 5:

Buscar datos de pokemon por medio de arbol heap -> 043 -> Oddish

### Prueba 6:

Buscar datos de pokemon por medio de arbol heap -> 150 -> Mewtwo

### Prueba 7:
Salir -> Resultado: Hasta luego entrenador!

