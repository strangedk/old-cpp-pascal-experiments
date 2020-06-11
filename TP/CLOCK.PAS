uses crt, graph;
var
   d, r, r1, r2, rr, k,
   x1, y1, x2, y2, x01, y01: integer;
   Xasp, Yasp: word;
begin
     d := detect;
     InitGraph(d, r, 'd:\tp7\bgi');

     begin
          x1 := GetMaxX div 2;
          y1 := GetMaxY div 2;
          GetAspectRatio(Xasp, Yasp);
          r := Round(2 * GetMaxY * Yasp / 8 / Yasp);
          r1 := Round(0.9 * r);
          r2 := Round(0.95 * r);

          Circle(x1,y1,r);
          Circle(x1,y1,round(1.02 * r));

          for k:=0 to 59 do
          begin
               if k mod 5=0 then
                  rr := r1
               else
                   rr := r2;
               x01 := x1+Round(rr * sin(2 * pi * k/60));
               y01 := y1-Round(rr * Xasp * cos(2 * pi * k/60) / Yasp);
               x2 := x1+Round(r * sin(2 * pi * k/60));
               y2 := y1-Round(r * Xasp * cos(2 * pi * k/60) / Yasp);
               Line(x01, y01, x2, y2);
          end;

          SetWriteMode(XORPut);
          SetLineStyle(SolidLn, 0, ThickWidth);
          r := 0;
          repeat
                for k:=0 to 59 do
                if not KeyPressed then
                   begin
                        x2 := x1+Round(0.85 * r1 * sin(2 * pi * r/60/12));
                        y2 := y1-Round(0.85 * r1 * Xasp * cos(2 * pi * r/60/12) / Yasp);
                        x01 := x1+Round(r2 * sin(2 * pi * k/60));
                        y01 := y1-Round(r2 * Xasp * cos(2 * pi * k/60) / Yasp);
                        Line(x1, y1, x2, y2);
                        Line(x1, y1, x01, y01);
                        Delay(6000);
                        Line(x1, y1, x2, y2);
                        Line(x1, y1, x01, y01);
                        inc(r);
                        if r=12*60 then
                           r := 0;
                   end;
          until KeyPressed;
          if ReadKey = #0 then k := ord(ReadKey);
          CloseGraph;
     end
end.