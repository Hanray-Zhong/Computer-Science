::ʹ�ñ�Я��VC6��MASM32ʱ���������������ȡ��ԭ��������cbox.bat������������cbox.exe
::���¼ٶ���Я��VC6��MASM32��װ��d:�̸�Ŀ¼������������Ӧ������
D:\VC6��MASM32\SDK\Masm32\bin\ml.exe  /c  /coff  /I"D:\VC6��MASM32\SDK\Masm32\include" cbox.asm
D:\VC6��MASM32\Common\MSDev98\Bin\rc.exe  cbox.rc
D:\VC6��MASM32\VC98\Bin\link.exe /subsystem:windows  /libpath"D:\VC6��MASM32\SDK\Masm32\lib" cbox.obj cbox.res
pause