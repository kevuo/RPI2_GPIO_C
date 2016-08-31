*----------------------------------------------------------*
* RPI2_GPIO_C											   *
* Dynamic C library created to access Raspberry Pi´s GPIOs.*
* 														   *
* Estudiantes:									           *
* Kevin Umaña Ortega - 201144881				           *
* Manuel Zumbado Corrales - 201033580			 		   *
*----------------------------------------------------------*

********************************* Respuesta a preguntas teóricas *********************************

1. ¿Qué pasos debe seguir antes de escribir o leer de un puerto de entrada/salida general (GPIO)?

	Los pasos a seguir previo a leer o escribir, desde o hacia un puerto, respectivamente, son:

	- Exportar el pin de tal manera que se permita el acceso a él.
	- Establecer si el pin es de entrada o salida.
	- Si el pin es de salida, se realiza una escritura con un valor determinado. 
	  En caso contrario, se lee el valor que el pin contiene.

2. ¿Qué comando podría utilizar, bajo Linux, para escribir a un GPIO específico?

	Debido a la naturaleza de Linux de representar los dispositivos como archivos, 
	es posible escribir valores por medio del comando "echo".

****************************** Guía para construir y utilizar la aplicación **********************

1. Ejecutar script para configuración de ambiente de compilación, utilizando el toolchain
   instalado. En este caso particular:

   . /opt/poky/2.1.1/environment-setup-cortexa7hf-neon-vfpv4-poky-linux-gnueabi

2. Ubicarse en el directorio principal del proyecto y escribir en la consola "make all".
   En caso de presentarse alguna anomalía, ejecutar primero "make clean" y luego
   "make all".

3. Insertar la tarjeta SD con la imagen de Linux creada para Raspberry Pi 2 y copiar
   tanto la biblioteca dinámica creada (libgpio.so), como el binario ya compilado (main)
   de la siguiente manera.

   La biblioteca se copia directamente al directorio lib, para que se
   busque automáticamente cuando el programa la requiere:

   	sudo cp lib/libgpio.so /media/kevin/75948f5b-5d4f-4822-8a63-0250d7af5411/lib/

   Se copia el archivo compilado "main" a la carpeta raíz del sistema:

   	sudo cp bin/main /media/kevin/75948f5b-5d4f-4822-8a63-0250d7af5411

4. Realizar la conexión de un LED y un resistor (1 kOhm) al pin GPIO elegido de la Raspberry Pi 2
   para llevar a cabo la función "blink". Recordar la conexión entre tierra de la plataforma y 
   el resistor empleado.

5. Extraer la tarjeta SD (con los dos archivos previamente mencionados ya copiados a ella) e
   insertarla en la Raspberry Pi 2. Encender la tarjeta, iniciar sesión como "root" e ingresar al
   directorio raíz del sistema de archivos.

   	cd /

6. Ejecutar el binario "main" y apreciar como el led parpadea durante un lapso de cinco segundos.

	./main

***************************************************************************************************