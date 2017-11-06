/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw3;
import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.Insertion;
import java.util.*;
/**
 *
 * @author gary
 */
public class HW3 {

    public static Double[] shufflearray(Double[] array)
    {
        Random rd = new Random();
        for (int i=0; i<array.length; i++)
        {
            int randomorder = rd.nextInt(array.length);
            double temp = array[i];
            array[i]=array[randomorder];
            array[randomorder]=temp;            
        }
        return array;
    }
    public static void main(String[] args) {
        // TODO code application logic here
       // MinPQ<String> pq = new MinPQ<String>();
       Random gen=new Random();
       //int n=100;
       for(int n=1; n<1000; n=n*2)
       {Double master_array[]=new Double[n],insert_array[]=new Double[n],minq_array[]=new Double[n];
        for(int i=0; i<n; i++)
        {
            master_array[i]=gen.nextDouble()*1000;
        }
        int j=0;
        master_array=shufflearray(master_array);
        
         for(int i=0; i<master_array.length; i++)
        {
            insert_array[i]=master_array[i];
            minq_array[i]=master_array[i];
            // System.out.println(master_array[i]);
        }
         long starttime=System.currentTimeMillis();
         Insertion.sort(insert_array);
         long endtime=System.currentTimeMillis();
         System.out.println("Insertion time and N: "+(endtime-starttime)+" "+n);
         
         long starttimeq=System.currentTimeMillis();
        MinPQ<Double> pq = new MinPQ<Double>();
        
        System.out.println("After insertion sorting....");
        
        for(int i=0; i<minq_array.length; i++)
        {
            pq.insert(minq_array[i]);
        }
        for(double m: pq)
        {
           // System.out.println(m);
            minq_array[j++]=m;
        }
        long endtimeq=System.currentTimeMillis();
        System.out.println("minpq time and N: "+(endtimeq-starttimeq)+" "+n);
        System.out.println("minq_array....");
       /*  for(int i=0; i<minq_array.length; i++)
        {
            System.out.println(minq_array[i]);
        }
         System.out.println("insertion....");
          for(int i=0; i<insert_array.length; i++)
        {
            System.out.println(insert_array[i]);
        }*/
        //StdOut.println("(" + pq.size() + " left on pq)");
       }
    }
}
