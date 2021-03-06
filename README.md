# SituacionProblemaDataEst
Repositorio para las evidencias de la clase de Estructuras de Datos. 

## Autores: 
Luis Fernández y
Jorge Pérez

## Research:
**ADT**

El ADT (Abstract Data Types), por sus siglas en inglés, es un tipo de dato el cual encapsula el funcionamiento e implementación de sus métodos. Dejándo sólo a la vista los métodos con los cuales el usuario puede interactuar. 

En este trabajo, los tipos de datos abstactos impletados son: 
1. CSV
2. Details
3. Filter
4. Search
5. ConeccionesComputadora
6. ConnectionManager

**Algorimos de búsqueda**

Durante estas 5 semanas hemos aprendido y conocido algunas de diferentes estructuras de datos, así como algoritmos de búsqueda. Sin embargo, decidimos ocupar quicksort para podenar por los **puertos?**, debido a lo siguente:

1. Es el algoritmo más eficiente con una complejidad de tipo O( n log2 n).

## Preguntas:

1. ¿Cuántos registros tiene tu archivo? 

De acuerdo a nuestro conteo: **36599** 

2. ¿Cuántos récords hay del segundo día registrado? ¿Qué día es este? 

El programa arrogó un total de **3302** registros. E identificó al segundo día como: **11-8-2020**.

3. ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?

Sí, detectamos que hay computadoras de **Katherine y Samuenl**

4. ¿Cuál es la dirección de la red interna de la compañía? 

Identificamos a reto.com como el servidor de la red interna. Así mismo, de acuerdo a Comparaiso, las computadoras tienen dos direcciones IP, la primera es local y cambia con cada dispostivo, así como una dirección pública. Debido a que todas las direcciones empezaban por 192.168.155.NN, creemos que la dirección del servidor de la compañía corresponde a la dirección IP de: **192.168.155.0**

Recuperado de: https://comparaiso.mx/tutoriales/como-saber-mi-ip


5. ¿Alguna computadora se llama server.reto.com? 

Según nuestro programa: **No** 

6. ¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)? 
Al preguntar por los sitos que se visitaban, el programa arrojó los siguientes resultados: 

freemailserver | washingtonpost | etsy | indeed | espn | apartments | quora | tripadvisor | businessinsider | nih | britannica | pinterest | rottentomatoes | retailmenot | wikihow | walmart | spotify | urbandictionary | theguardian | facebook | target | imdb | wayfair | instagram | yahoo | msn | twitter | webmd | linkedin | chase | google | craigslist | huffpost | groupon | bestbuy | live | hulu | fandom | dictionary | youtube | usnews | usps | allrecipes | irs | foxnews | wellsfargo | accuweather | quizlet | mapquest | gamepedia | paypal | wiktionary | cnet | medicalnewstoday | usatoday | ebay | steampowered | office | steamcommunity | yelp | netflix | glassdoor | genius | forbes | wikipedia | cbssports | investopedia | lowes | ca | healthline | macys | apple | bankofamerica | go | aol | expedia | reddit | foodnetwork | microsoft | weather | homedepot | xfinity | bbb | npr | merriam-webster | ign | amazon | yellowpages | techradar | roblox | bleacherreport | cnn | zillow | mayoclinic | nytimes | fb | 8w2v29sbezi1btcj4txw | euo5ychfvuhangmtt8uh

Creemos que el número de sitos de correo se puede reducir al crear un filtro doble. Donde se obtengan los resultados únicos de los sitios visitados y el número de puerto que lo representa. 

7. Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente. 

**Puerto:**
1. *53*: Domain Name System (DNS)
2. *67*: Dynamic Host Configuration Protocol (DHCP)
3. *993*: Internet Message Access Protocol over Secure Sockets Layer (IMAPS)
4. *465*: Simple Mail Transfer Protocol over Secure Sockets Layer (SMTPS)
5. *443*: HTTP with Secure Sockets Layer (SSL) 
6. *80*: HyperText Transfer Protocol (HTTP)
7. *965*: 404, no se encontró registro
8. *135*: RPC (Remote Protocol Call)/DCOM

La información fue obtenida de: https://www.utilizewindows.com/list-of-common-network-port-numbers/ y de: https://web.mit.edu/rhel-doc/4/RH-DOCS/rhel-sg-en-4/ch-ports.html

## TODO list/Repartición de tareas:
- [x] Crear clase CSV -> J
- [x] Crear clase Details -> L
- [x] Crear respuesta a pregunta 4, 2 y 3 -> J
- [x] Crear respuesta a pregunta 1, 5, 6 y 7 -> L

## Reflexiones personales:

### Jorge
Durante este proyecto tuve la oportunidad de trabajar con archivos .csv, lo cual era algo que nunca había hecho en C++. También pude cuestionar los usos que le doy a las computadoras, ya que el escoger los algoritmos que resuleven el problema de manera óptima tiene una gran diferencia. Ya que antes de implementar este tipo de métodos sólo ocupaba búsquedas líneales. Las cuales no son del todo eficientes. A pesar de que ahora sé ocupar nuevos métodos para organizar la información, también aprendí la esencialidad de reccorrer todos los datos, ya que es la única manera que se puede hacer conteo de cosas. Es eso o usar un índice, sin embargo, aún no logro comprender del todo cómo funcionan.

Como parte de mi invesigación: aprendí que la parte más importante de un programa es su correcicción (que ejegute con exactitud sus tareas), y su eficiencia (usar la menor cantidad de recursos de hardware).

Es por eso que la eficacia de los algoritos de búsqueda y su unión con estructuras de datos que tomen ventaja de ellos son necesarias, ya que a pesar de tener un buen algoritmo, puede que no se aproveche todo el potencial por no tener la estructura correcta. 

En un breve resumen, no debemos de ocupar el agoritmo burbuja por su alta cantidad de comparaciones y comportamiento O(n2). Mientras que el quicksort es 99% más eficiente que el burbuja, por su complejidad O( n log2 n). Ya que se reduce drásticamente el número de compraciones que el método burbuja y su funcionamiento similar a una búsqueda binaria. 

Un ejemplo donde la eficiencia es crucial es en un sistma de inscripciones de miles de personas, como el del Politécnico Nacional, o los almacenes de Amazon.


### Luis
Algo que no había hecho nunca con C++ era trabajar con archivos, todo había sido con datos nativos o clases construidas a partir de esto pero jamás con datos de forma masiva, lo cual lo hizo un reto interesante. Al principio mi idea era hacer todas estas diferentes clases para administrar cada sección a partir de Templates pero me di cuenta que para un proyecto tan específico es mejor hacerlo más detallado para el problema en si que para reciclar el códido. Algo que me pareció muy bueno fue buscar los diferntes tipos de búsqueda y de filtros(ordenamiento) y aprender con datos reales a implementar las soluciones, así como a decidir cual es el que conviene cuando de verdad se necesita, no solamente decidir por tener todas las opciones. 

Para hacer este proyecto en específico creo que también tuvimos que hacer mucha investigación acerca de los diferentes algoritmos que habían y además al programarlo nos dimos cuenta creo que un par de debilidades que teníamos al programar en la que no confiabamos tanto en las estructuras, y tuvimos, o al menos yo tuve que aprender a confiar más en las diferentes estructuras. 


## Reflexiones personales (Segunda Parte):

### Jorge:
Durante el desarrollo de este entregable me percaté de la necesidad de implementar estructuras de datos linéales, debido a que constantemente me encontraba realizando for loops, los cuales iban incrementando poco a poco la complejidad del algoritmo. Lo cual lo hace ineficiente. También, realicé una pequeña investigación de qué era un vector. Con esto me di cuenta de su versatilidad, ya que se comporta de manera similar a una lista de arrays, (están agrupados en memoria). Lo que ayuda a reducir su tiempo de escritura y lectura, sin perder la posibilidad de poder cambiar su tamaño. 
Algo que aún no me queda claro, es cúando debemos de utilizar cada estructura, para que se note esta mejora en rendimiento. Lo cual busco completar en un futuro.
### Luis:
Este entregable fue muy difícil de hacer, durante la semana previa a la fecha de entrega fue muy difícil planear una asesoría porque muchas clases han pedido tareas por las mismas fechas, por lo que este entregable fue un poco complicado de entender al cien. En lo personal la programación de esta parte se me hizo muy confuso porque quería utilizar la mayoría de lo que ya habíamos programado en vez de iniciar algo nuevo pero las clases no coincidieron mucho para lo que se pedía en específico. Creo que algo que nos faltó esta vez fue realmente entender este reto y poder tener un poco más de tiempo para rehacer el código anterior que, aunque si había salido, no funcionaba para todo lo que lo íbamos a necesitar ahora. Algo que también creo es que es confuso saber que estructura utilizar que no sea vector porque los vectores es lo que más utilizamos y las demás podrían ser lo mismo pero identificarla tal cual es lo complicado.
