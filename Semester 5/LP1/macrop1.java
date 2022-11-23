package macro1;

import java.io.*;
import java.io.File;  // Import the File class
import java.io.FileWriter;   // Import the FileWriter class
import java.util.*;

public class mpass1 
{
   public static void main(String args[])throws IOException 
   {
      FileWriter MDT = new FileWriter("MDT.txt");
      FileWriter MNT = new FileWriter("MNT.txt");
      FileWriter KPDTAB = new FileWriter("KPDTAB.txt");
      File input=new File("input.txt");
      
      FileReader fr=new FileReader(input);
      BufferedReader br=new BufferedReader(fr);
      String line;
      
      LinkedHashMap<String, String> kpdtab = new LinkedHashMap<>();
      
      ArrayList<String> name = new ArrayList<String>(2);
      ArrayList<String> pntab = new ArrayList<String>(2);

      ArrayList<Integer> pp = new ArrayList<Integer>(2);
      ArrayList<Integer> kp = new ArrayList<Integer>(2);
      ArrayList<Integer> mdt = new ArrayList<Integer>(2);
      ArrayList<Integer> kpdt = new ArrayList<Integer>(2);
      int l=0;
      
      while((line=br.readLine())!=null)
      {
         l++;
         String[] a=line.split("[ ]");
         if(a[0].equals("MEND")) 
         {
            l--;
            pntab.removeAll(pntab);continue;
         }
         if(a[0].equals("MACRO"))
         {
            kpdt.add(kpdtab.size()+1);
            line=br.readLine();
            pntab = new ArrayList<String>(2);
            String p[]=line.split("[ ,]");
            name.add(p[0]);
            int np=0,nk=0;
            for(int i=1;i<p.length;i++)
            {
               if(p[i].indexOf('=')!=-1)
               {
               pntab.add(p[i].substring(0,p[i].indexOf('=')));
               nk++;
               p[i]=p[i]+" ";
               kpdtab.put(p[i].substring(0,p[i].indexOf('=')),p[i].substring(p[i].indexOf('=')+1));
            }
            else 
            {
               np++;pntab.add(p[i]);}
            }
            pp.add(np);
            kp.add(nk);
            mdt.add(l);
            continue;
         }
         if(!a[0].equals("MACRO"))
            for(int i=0;i<a.length;i++) 
            {
               if(pntab.contains(a[i]))
                  MDT.write("(P,"+(pntab.indexOf(a[i])+1)+") ");
               else
                  MDT.write(a[i]+" ");
            }
         MDT.write("\n");
      }

      for(int i=0;i<name.size();i++)
      {
         MNT.write(name.get(i)+" "+pp.get(i)+" "+kp.get(i)+" "+mdt.get(i)+" "+kpdt.get(i)+"\n");
      }

      System.out.println("KPDTAB");
      Set<String> keys = kpdtab.keySet();
      for (String key : keys) 
      {
           KPDTAB.write(""+key+":"+kpdtab.get(key)+"\n");
      }
      MDT.close();
      MNT.close();
      KPDTAB.close();
      fr.close();
   }
}
