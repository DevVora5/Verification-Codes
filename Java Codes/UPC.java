import java.util.*;
public class UPC
{
    Scanner ob=new Scanner(System.in);
    public int isvalidupc(double upc)
    {
        int len=String.valueOf(upc).length();
        if(len!=12)
            return 1;
        double sum=0,digit=0,num=upc;
        for (int i=0;i<13;i++)
        {
            digit=num%10;
            if(i%2==0)
                sum+=digit*1;
            else
                sum+=digit*3;
            num=num/10;
        }
        if(sum%10==upc%10)
            return 1;
        else
            return 0;
    }
    public void main()
    {
        System.out.println("Enter the ups code to be verified : ");
        double code=ob.nextDouble();
        if(isvalidupc(code)==1)
            System.out.println("Valid");
        else
            System.out.println("Invalid");
    }
}
