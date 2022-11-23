package macro;

import java.util.*;
import java.io.*;
import java.io.File;  // Import the File class
import java.io.FileWriter;

public class pass2 
{
    public static void main(String args[])throws IOException 
    {
        LinkedHashMap<String, String> kpdtab = new LinkedHashMap<>();
        
        ArrayList<String> aptab = new ArrayList<String>(2);
        ArrayList<String> name = new ArrayList<String>(2);
        
        ArrayList<Integer> pp = new ArrayList<Integer>(2);
        ArrayList<Integer> kp = new ArrayList<Integer>(2);
        ArrayList<Integer> mdt = new ArrayList<Integer>(2);
        ArrayList<Integer> kpdt = new ArrayList<Integer>(2);
        
        File input=new File("KPDTAB.txt");
        FileReader fr=new FileReader(input);
        BufferedReader br=new BufferedReader(fr);
        String line;
        
        FileWriter output = new FileWriter("output1.txt");
        
        while((line=br.readLine())!=null)
        {
            String[] a=line.split("[:]");
            kpdtab.put(a[0],a[1]);
        }
        input = new File("MNT.txt");
        fr = new FileReader(input);
        br = new BufferedReader(fr);
        
        while((line=br.readLine())!=null)
        {
            String[] a=line.split("[ ]");
            name.add(a[0]);
            pp.add(Integer.parseInt(a[1]));
            kp.add(Integer.parseInt(a[2]));
            mdt.add(Integer.parseInt(a[3]));
            kpdt.add(Integer.parseInt(a[4]));
        }
        input = new File("calls.txt");
        fr = new FileReader(input);
        br = new BufferedReader(fr);
        while((line=br.readLine())!=null) 
        {
            if(line.substring(0,4).equals("CALL"))
            {
                int index;
                aptab = new ArrayList<String>(2);
                LinkedHashMap<String, String> kpdtabcopy = new LinkedHashMap<>();
                kpdtabcopy.putAll(kpdtab);
                String []a=line.split("[, ]");
                index=name.indexOf(a[1]);
                for(int i=2;i<a.length;i++)
                {
                    if(a[i].indexOf('=')==-1)
                        aptab.add(a[i]);
                }
                Set<String> keys = kpdtab.keySet();
                for(int i=1;i<a.length;i++)
                {
                    if(a[i].indexOf('=')!=-1)
                    {
                       if(!a[i].substring(1+a[i].indexOf('=')).equals(" "))
                        kpdtab.put(a[i].substring(0,a[i].indexOf('=')), a[i].substring(1+a[i].indexOf('=')));
                    }
                }
                int cnt=0;
                for (String key : kpdtab.keySet()) 
                { 
                    cnt++;
                    if(cnt<kpdt.get(index)-1) 
                    {
                        continue;
                    }
                    if(cnt>kpdt.get(index)+kp.get(index))
                        break;
                    if(!kpdtab.get(key).equals(" "))
                     aptab.add(kpdtab.get(key));
                }
                for(int i=0;i<aptab.size();i++)
                    System.out.println(aptab.get(i));
                File input1=new File("MDT.txt");
                FileReader fr1=new FileReader(input1);
                BufferedReader br1=new BufferedReader(fr1);
                String line1;
                int start=mdt.get(index),end=99999999;
                if(index!=mdt.size()-1)end=mdt.get(index+1);
                int count=0;
                while((line1=br1.readLine())!=null) 
                {
                    count++;
                    if(count<start-1)continue;
                    if(count>=end-1)break;
                    String b[]=line1.split("[ ]");
                    for(int i=0;i<b.length;i++)
                    {
                        if(b[i].charAt(0)=='(')
                        {
                            output.write(""+aptab.get(-1+Integer.parseInt(b[i].substring(3,b[i].length()-1))));
                            if(i!=b.length-1)
                                output.write(",");
                        }
                        else
                            output.write(""+b[i]+" ");
                    }
                    output.write("\n");
                }
                fr1.close();
                kpdtab.putAll(kpdtabcopy);
            }
            else
                output.write(""+line+"\n");
        }
        output.close();
    }
}
