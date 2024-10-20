# 10 Ejemplos de C
<sub>Algunos con graphics.h</sub>

Este repo recopila **10 ejemplos basicos** de C que yo **Kmz Kuro** he logrado aprender a lo largo del curso de **fundamentos de programacion**. Dentro de si, encontraremos programas que haran uso de la libreria **<graphics.h>** esto requiere de que configures tu entorno de desarrollo de forma correcta, pero no te preocupes si no lo sabes hacer, aqui mismo te mostrare como hacerlo dependiendo de si usas **Visual Studio Code** o **Dev-C++**

## Configurar tu entorno de desarrollo

### Dev-C++

Dev C++ es una IDE que te permite codificar, compilar y ejecutar tu codigo de C/C++, esta se instala a traves de [Este enlace](https://sourceforge.net/projects/orwelldevcpp/files/latest/download).

Sigue los pasos de instalacion y seguido de esto podras configurar la IDE a tu gusto. Este a diferencia de Visual Studio Code no requiere de otras instalaciones y configuraciones complejas ya que por si mismo trae incorporado el compilador y todo lo necesario para poder ejecutar tu codigo.

![Imagen de referencia](./archivos/imagenes/p8.png)

Para compilar y ejecutar dentro de este IDE presionaremos en el cuadro de colores rojo, verde, azul y amarillo y con este se estara ejecutando.

### Visual studio code

#### Instalacion de MinGW64.

Este es un entorno que contiene GCC el cual es el compilador de c y c++, este es necesario para la interpretacion y ejecucion del codigo c/c++.\
Para instalarlo puedes visitar https://winlibs.com/ y en la parte donde vienen las descargas instalar el zip correspondiente dependiendo de tu sistema.

> A partir de aqui me he equivocado en una cosa, no se va a usar la version de 64 bits, sino la de 32 debido a que graphics.h unicamente puede ejecutarse sobre 32 bits...\
> El procedimiento es el mismo sin embargo en vez de mingw64 sera mingw32, en la imagen es el zip que esta arriba del marcado.

![Imagen de referencia](./archivos/imagenes/p1.png)

Una vez hayas descargado el zip tendras que extraer la carpeta que se encuentra dentro del zip en tu unidad **C**, de modo que quede **c:/mingw32**.

![Imagen de referencia](./archivos/imagenes/p2.png)

Una vez el proceso haya terminado, copiaremos la ruta `C:\mingw32\bin` y seguido de esto abriremos las variables del entorno escribiendo en la barra de busqueda de nuestro sistema operativo "Variables del entorno", esto mostrara la siguente opcion `Editar las variables del entorno del sistema` haremos clic en esa opcion, esto nos desplegara un cuadro llamado `Propiedades del sistema`.

Dentro del cuadro presionaremos la opcion `Variables del entorno` que nos abrira otro cuadro, **mucho cuidado con mover otras cosas que no estan dentro de las siguentes insrucciones:**

En el apartado variables del sistema buscaremos la opcion `Path` y haremos doble clic sobre la misma, seguido de esto, seleccionaremos la opcion `nuevo` y pegaremos la ruta que copiamos anteriormente en el espacio, proximo a esto daremos aceptar en todo.

![imagen de referencia](./archivos/imagenes/p3.png)

hecho esto tendremos finalmente configurado el compilador de c en nuestro ordenador, para verificarlo presionaremos las teclas `Win` + `R` y en el cuadro emergente escribiremos `powershell` y daremos enter. Dentro de powershell escribiremos lo siguente `gcc --version` y se tendra que mostrar la version del compilador.

![imagen de referencia](./archivos/imagenes/p4.png)

Hemos terminado la parte de configurar el compilador, ahora viene configurar Visual Studio Code.

#### Instalacion y configuracion de Visual Studio Code

La instalacion de VSCode es muy intuitiva, solo te dare el link directo a la descarga [Justo aqui](https://code.visualstudio.com/docs/?dv=win64user) y seguir las instrucciones de instalación.\
Una vez instalado selecciona el apartado extensiones en la barra lateral de la izquierda y busca la extension `Code Runner` hecho esto vamos a la configuracion de la extension y buscaremos la opcion `Run in Terminal`, tendremos que marcar esta opcion como activa unicamente presionando en el cuadro del checkmark.

![imagen de referencia](./archivos/imagenes/p5.png)

Finalmente buscaremos la opcion `Executor Map` y presionaremos en Editar settings.json, nos saltara un archivo json en el editor, dentro de este buscaremos la siguente linea:\
`"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"`\
la cual remmplazaremos por lo siguente:\
`"cpp": "g++ '$dirWithoutTrailingSlash\\$fileName' -o '$workspaceRoot\\$fileNameWithoutExt' && start cmd \"/k ; $workspaceRoot\\$fileNameWithoutExt & echo. & pause & exit\" && exit"`\
De modo que quede algo parecido a esto:

![imagen de referencia](./archivos/imagenes/p6.png)

Guarda todo con `Ctrl` + `S` y unicamente tendras que presionar `Ctrl` + `Alt` + `N` para correr el codigo o presionar el boton de ejecutar en la parte superior derecha de la ventana

![imagen de referencia](./archivos/imagenes/p7.png)