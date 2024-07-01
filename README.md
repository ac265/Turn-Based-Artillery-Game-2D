# Turn-Based-Artillery-Game-2D
Proje, FreeGLUT ve C++ kullanılarak geliştirilecek bir 2D turn-based (sıra tabanlı) topçu oyunudur.


## Kurulum, Derleme ve Çalışma Talimatları

### Kurulum

A - Visual Studio Community 2022
--------------------------------

1) Desktop development with C++ seçilerek kurulum yap.
2) Tümünü indir ve sonra yükle'yi seç ve yükle'ye tıkla.

B - Freeglut
--------------------------------

1) freeglut.sourceforge.net sitesine git.
2) Download'a tıkla.
3) Prepackaged Releases altında yer alan Martin Payne's Windows Binaries(MSVC and MinGW)'e tıkla.
4) freeglut 3.0.0 MSVC Package'a gel.
5) Download freeglut 3.0.0 for MSVC(with PGP signature and PGP key)'ye tıkla.
6) İndirilen zip dosyasını ayıkla.
7) freeglut/bin altına Win32 klasörü oluşturularak freeglut.dll'i bu dosyaya taşı.
8) freeglut/lib altına Win32 klasörü oluşturularak freeglut.lib'i bu dosyaya taşı.
9) Proje klasörünün altına Dependencies klasörü oluşturarak düzenlenen freeglut klasörünü buraya taşı.
10) Proje'yi seç Properties'e tıkla.
11) General > C++ Language Standard > ISO C++ 17 Standard(std:c++ 17) 'yi seç.
12) Apply'a tıkla.
13) Configuration > All Configurations'ı seç
14) Platform > All Platforms'u seç.
15) VC++ Directories > Include Directories > Edit > "$(SolutionDir)Dependencies\freeglut\include" > OK > Apply
16) VC++ Directories > Library Directories > Edit > "$(SolutionDir)Dependencies\freeglut\lib\$(Platform)" > OK > Apply
17) Linker > Input > Additional Dependencies > Edit > freeglut.lib > OK > Apply 
18) Build Events > Post-Build Event > Command Line > Edit > copy "$(SolutionDir)Dependencies\freeglut\bin\$(Platform)\freeglut.dll" "$(OutDir)" > OK > Apply

C - OpenGL
--------------------------------

1) https://www.glfw.org sitesine git.
2) Download'a tıkla.
3) Windows pre-compiled binaries > 64-bit Windoes binaries tıkla ve indir.
4) Zip dosyasını ayıkla.
5) Project > Properties'e tıkla.
6) C/C++ > General > Additional Include Directories > Edit > Klasör Seç > glfw-3.4.bin.WIN64 > Include > Select Folder > OK > Apply
7) Linker > General > Additional Library Directories > Edit > Klasör Seç > glfw-3.4.bin.WIN64 > lib-vc2022 > Select Folder > OK > Apply
8) Linker > Input > Additional Dependencies > Edit > glfw3.lib , opengl32.lib ,  user32.lib , gdi32.lib ve shell32.lib ' ekle > OK > Apply > OK  

### Derleme

1) Build > Rebuild

### Çalıştırma 

1) Local Window Debugger'a tıklayarak çalıştır.



