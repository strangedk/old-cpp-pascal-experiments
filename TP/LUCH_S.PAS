{	�ணࠬ�� ��⠢�� ��ਭ� �.�.-�९�����⥫� ��䥤���
	���ଠ樮���� �孮����� �������, ⥫.23-27-93. }
	Uses Crt;
   Label FinitaLaCommedia;
   Var x0,y0,x1,y1,eps,a,b,c,d,r:extended;
			       s:char;
Begin ClrScr;
WriteLn('�� ��࠭�稢�� ��魮��, ��ᬮ�ਬ ��� ࠤ��� R � 業�஬ � ��砫� ���न���!');
Write('������ ࠤ��� ��㣠 R='); ReadLn(R);
Write('������ ������ ����७��� �窨 ��㣠 �0='); ReadLn(x0);
Write('������ �न���� ����७��� �窨 ��㣠 y0='); ReadLn(y0);
WriteLn('��� 㤮��⢠ �롮� �窨 �� ���㦭��� ������ �㤥� ��।����� ������, �      �न���� �������!');
Write('������ ������ �窨 ���㦭��� �1='); ReadLn(x1);
       y1:=-Sqrt(R*R-x1*x1);
WriteLn('�롥६ ��� �� ���孥� ���㮪�㦭���? �� - Y, ��� - N.');
       ReadLn(s);  if ((s='Y') or (s='y')) then y1:=-y1;
WriteLn('�न��� �窨 ���㦭�c� y1=',y1:13:11); WriteLn;
		       { ��砫� �����⬠! }
	 a:=y1-y0; b:=x0-x1; c:=y0*x1-x0*y1; d:=Abs(c/Sqrt(a*a+b*b));
   if Abs(d)<1E-33 then begin
WriteLn('��� ᢥ� �ன��� �१ 業�� ��㣠 �� ��� ��᫥ ��ࢮ�� ��ࠦ���� �� ���㦭���');
		     goto FinitaLaCommedia end
       else
WriteLn('��� ᢥ� �㤥� ��室��� ���� 業�� ��㣠 �� �������쭮� ����ﭨ�');
WriteLn;
WriteLn('                           d=',d:13:11,' !');
FinitaLaCommedia:
WriteLn('Press Enter'); ReadLn;
End.
