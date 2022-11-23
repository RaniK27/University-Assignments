package assembler;
import java.io.*;
import java.util.*;
import java.io.File; // Import the File class
import java.io.FileWriter; // Import the FileWriter class
public class pass2 {
public static void main(String args[])throws IOException {
FileWriter myObj = new FileWriter("output.txt");
File input=new File("littab.txt");
FileReader fr=new FileReader(input);
BufferedReader br=new BufferedReader(fr);
String line;
int lc=0;
ArrayList<Integer> l = new ArrayList<Integer>(2);
ArrayList<Integer> s = new ArrayList<Integer>(2);
l.add(0);s.add(0);
while((line=br.readLine())!=null)
{ String[] a=line.split("[:]");
l.add(Integer.parseInt(a[1]));
} fr.close();
input=new File("symbtab.txt");
fr=new FileReader(input);
br=new BufferedReader(fr);
while((line=br.readLine())!=null)
{ String[] a=line.split("[:]");
s.add(Integer.parseInt(a[1]));
}
fr.close();
input=new File("IC.txt");
fr=new FileReader(input);
br=new BufferedReader(fr);
while((line=br.readLine())!=null)
{ line=line.replace(" ", "
");
// System.out.println(line);
String[] a=line.split("[ ]");
if(line.length()==0)continue;
for(int i=0;i<a.length;i++) {
if(a[i].charAt(0)=='(')
a[i]=a[i].substring(1,a[i].length()-1);
//System.out.println(a[i]);
} if(a[0].equals("AD,1")) {
lc=Integer.parseInt(a[1].split("[,]")[1]);
continue;
} if(!a[0].substring(0,2).equals("AD"))
myObj.write(""+lc+") ");
if(a[0].equals("AD,3")) {
lc=0;
//fetch a[1] from table
if(a[1].charAt(0)=='S')
lc=s.get(Integer.parseInt(a[1].split("[,]")[1]));
else if(a[1].charAt(0)=='L')
lc=+l.get(Integer.parseInt(a[1].split("[,]")[1]));
else if(a[1].charAt(0)=='C')
lc=Integer.parseInt(a[1].split("[,]")[1]);
else
myObj.write("ERROR");
// add or subtract a[2].substring(1,);
//System.out.println(line+"whyyy"+a[1]);
if(a.length>2) {
if(a[2].charAt(0)=='+')
lc=lc+Integer.parseInt(a[2].substring(1));
else
lc=lc-Integer.parseInt(a[2].substring(1));}
continue;
} if(a[0].equals("IS,0")) {
myObj.write("0 0 000\n");
continue;
} if(a[0].substring(0,2).equals("IS")) {
int x=Integer.parseInt(a[0].split("[,]")[1]);
myObj.write(""+x+" ");
}
if(a[0].equals("DL,01")) {
int x=Integer.parseInt(a[1].split("[,]")[1]);
myObj.write("0 ");
} if(a[0].equals("DL,2")) {
int x=Integer.parseInt(a[1].split("[,]")[1]);
myObj.write("\n");
for(int i=1;i<=x;i++) {lc++;
if(i==1)continue;
myObj.write(""+lc+")\n");
}continue;
} if(a[0].substring(0,2).equals("AD"))
continue;
if(a.length>1)
{
if(a[1].charAt(0)=='S')
myObj.write("0 "+s.get(Integer.parseInt(a[1].split("[,]")[1]))+" ");
else if(a[1].charAt(0)=='L')
myObj.write("0 "+l.get(Integer.parseInt(a[1].split("[,]")[1]))+" ");
else if(a[1].charAt(0)=='C')
myObj.write("0 "+Integer.parseInt(a[1].split("[,]")[1])+" ");
else {
myObj.write(Integer.parseInt(a[1])+" ");}
}
if(a.length>2)
{ if(a[2].charAt(0)=='S')
myObj.write(""+s.get(Integer.parseInt(a[2].split("[,]")[1]))+" ");
else if(a[2].charAt(0)=='L')
myObj.write(""+l.get(Integer.parseInt(a[2].split("[,]")[1]))+" ");
else if(a[2].charAt(0)=='C')
myObj.write(""+Integer.parseInt(a[2].split("[,]")[1])+" ");
}
myObj.write("\n");
if(!a[0].equals("AD,1"))
lc++;
} fr.close();
myObj.close();
}}
