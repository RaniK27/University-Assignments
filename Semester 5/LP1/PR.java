import java.util.Scanner;
import java.io.*;

class PageReplacement{
    String frame[];
    String line[];
    Scanner sc = new Scanner(System.in);
    int front, back, faults;
    
    //default constructor
    PageReplacement()
    {
        try{
            System.out.print("Enter the number of frames: ");
            frame = new String[sc.nextInt()];
            
        }
        catch(Exception e){
            System.out.println("Please enter a valid number.");
            System.exit(0);
        }
    }
    
    //to clear the contents of queue
    void clear()
    {
    	for(int i=0; i<frame.length;i++)
        {
        	frame[i] = "-";
        }
    	front = back = faults = 0;
    }
    
    //to check if frames are empty
    boolean isEmpty()
    {
    	for(int i=0; i<frame.length;i++)
    	{
    		if(frame[i].equals("-"))
    			return true;
    	}
    	return false;
    }
    
    //to search for a frame in the queue
    int Search(String x)
    {
    	for(int i=0; i<frame.length;i++)
    	{
    		if(frame[i].equalsIgnoreCase(x))
    			return i;
    	}
    	return -1;
    }
    
    //function to display the frame
    void display()
    {
    	for(int i=0;i<frame.length;i++)
    	{
    		System.out.print("| "+frame[i]+" ");
    	}
    }
    
    int calcOPT(int index)
    {
    	int found[] = new int[frame.length];
        int count = frame.length;
    	for(int i = index; i<line.length;i++)
    	{
    		if(Search(line[i])!=-1)
            {
                found[Search(line[i])] = 1;
                count--;
                if(count == 1)
                {
                    break;
                }
            }
    	}

        //FIFO check for unencountered page
        for(int i = 0; i<found.length;i++)
        {
            if(found[i]!=1)
            {
                return i;
            }
        }
        //edge case return 	
    	return 0;
    }

    int calcLRU(int index)
    {
    	int found[] = new int[frame.length];
        int count = frame.length;
    	for(int i = index; i>=0;i--)
    	{
    		if(Search(line[i])!=-1)
            {
                found[Search(line[i])] = 1;
                count--;
                if(count == 1)
                {
                    break;
                }
            }
    	}

        //FIFO check for unencountered page
        for(int i = 0; i<found.length;i++)
        {
            if(found[i]!=1)
            {
                return i;
            }
        }
        //edge case return 	
    	return 0;
    }
    
    //FIFO page replacement algorithm
    void FIFO()
    {
    	//clearing the frames queue
    	clear();
    	for(int i = 0; i<line.length;i++)
        {
    		System.out.println("\nSearching for => "+line[i]);
        	if(Search(line[i])!=-1)
        	{
        		System.out.println("Page found!");
        	}
        	else
        	{
        		System.out.println("Page not found!");
        		faults++;
        		if(isEmpty())
        		{
        			frame[back++] = line[i];
        		}
        		else
        		{
        			frame[front] = line[i];
        			front = (front+1)%frame.length;
        		}
        		display();
        		System.out.println("\nPage added to frame!");
        	}
        }
    	
    	System.out.println("\nTotal number of page faults: "+faults);
    }
    
    //OPT page replacement algorithm
    void OPT()
    {
    	//clearing the frames queue
    	clear();
    	for(int i = 0; i<line.length;i++)
        {
    		System.out.println("\nSearching for => "+line[i]);
        	if(Search(line[i])!=-1)
        	{
        		System.out.println("Page found!");
        	}
        	else
        	{
        		System.out.println("Page not found!");
        		faults++;
        		if(isEmpty())
        		{
        			frame[back++] = line[i];
        		}
        		else
        		{
                    System.out.println("Replacing farthest occuring page: "+frame[calcOPT(i)]);
        			frame[calcOPT(i)] = line[i];
        		}
                display();
        		System.out.println("\nPage added to frame!");

        	}
        }
        System.out.println("\nTotal number of page faults: "+faults);	
    }
    	
    
    //LRU page replacement algorithm
    void LRU()
    {
        //clearing the frames queue
    	clear();
    	for(int i = 0; i<line.length;i++)
        {
    		System.out.println("\nSearching for => "+line[i]);
        	if(Search(line[i])!=-1)
        	{
        		System.out.println("Page found!");
        	}
        	else
        	{
        		System.out.println("Page not found!");
        		faults++;
        		if(isEmpty())
        		{
        			frame[back++] = line[i];
        		}
        		else
        		{
                    System.out.println("Replacing least recently used page: "+frame[calcLRU(i)]);
        			frame[calcLRU(i)] = line[i];
        		}
                display();
        		System.out.println("\nPage added to frame!");

        	}
        }
        System.out.println("\nTotal number of page faults: "+faults);	
    	
    }
    
    public static void main(String[] args) throws IOException{
    	try (Scanner sc = new Scanner(System.in)) {
            PageReplacement obj = new PageReplacement();
            //to read from the cmd
            
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            System.out.print("Please enter all pages required by program in order: ");
            String script = br.readLine();
            obj.line = script.split(" ");
            int choice = 0;
            while(choice != -1)
            {
            	System.out.println("\nMENU\n1. FIFO\n2. OPTIMAL\n3. LRU\n-1. EXIT");
            	System.out.print("Enter your choice from menu: ");
            	choice = sc.nextInt();
            	switch(choice)
            	{
            	case 1:
            		obj.FIFO();
            		break;
            		
            	case 2:
            		obj.OPT();
            		break;
            		
            	case 3:
            		obj.LRU();
            		break;
            		
            	case -1:
            		System.out.println("Thank you");
            		break;
            	}
            }
        }
        catch (Exception e) {
            System.out.println("Please enter valid values!\n"+e);
        }
        
    }
}
