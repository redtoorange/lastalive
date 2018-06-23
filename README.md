#Folder Structure:
##Binaries:
	/bin
		Contains the binary files that need to be present next to the .exe to run correctly.  The files needed depends on the machine
		architecture used for building.
		
		/x64
			Contains the .dll files needed to for the program to run on a 64-bit machine.
				glew32.dll, libjpeg-9.dll, libpng16-16.dll, libtiff-5.dll, libwebp-7.dll, SDL2.dll, SDL2_image.dll, zlib1.dll
		/x86
			Contains the .dll files needed to for the program to run on a 32-bit machine
				glew32.dll, libjpeg-9.dll, libpng16-16.dll, libtiff-5.dll, libwebp-7.dll, SDL2.dll, SDL2_image.dll, zlib1.dll
				
##Includes:
	/includes
		Contains the include directories for the individual libraries in a single location.  To maintain the best functionality, add
		each subfolder to your additional includes in Visual Studio.
		
		/glew
		/SDL
		/SDL_image

##Libraries:
	/lib
		Contains the .lib files for the different libraries.  You will need to add the /lib folder to additional libraries and then
		add the specific files to the link path.  The exact line to add it found in the Set up section.
		
		/x64
			Contains the .lib files needed to add to the link path for 64-bit.
				glew32.lib; SDL2.lib; SDL2main.lib; SDL2test.lib; SDL2_image.lib;
		/x86
			Contains the .lib files needed to add to the link path for 32-bit.
				glew32.lib; SDL2.lib; SDL2main.lib; SDL2test.lib; SDL2_image.lib;
				
##Legal:
	/licenses
		Contains all the license information for all libraries used.
	
	
	
#Setting up project:
	1) Additional includes, add the three folders in the includes directory.
	2) Additional libraries, add the path to the lib folder of the correct architecture.
	3) Linker, add the files from the .lib folder:
		opengl32.lib; glew32.lib; SDL2.lib; SDL2main.lib; SDL2test.lib; SDL2_image.lib;
	4) Copy the correct bin files to the directory where the .exe will be created.