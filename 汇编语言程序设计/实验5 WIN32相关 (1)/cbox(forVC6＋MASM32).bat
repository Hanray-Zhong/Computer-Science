::使用便携版VC6＋MASM32时，运行这个批处理（取代原有批处理cbox.bat），即可生成cbox.exe
::以下假定便携版VC6＋MASM32安装到d:盘根目录，否则自行相应调整。
D:\VC6＋MASM32\SDK\Masm32\bin\ml.exe  /c  /coff  /I"D:\VC6＋MASM32\SDK\Masm32\include" cbox.asm
D:\VC6＋MASM32\Common\MSDev98\Bin\rc.exe  cbox.rc
D:\VC6＋MASM32\VC98\Bin\link.exe /subsystem:windows  /libpath"D:\VC6＋MASM32\SDK\Masm32\lib" cbox.obj cbox.res
pause