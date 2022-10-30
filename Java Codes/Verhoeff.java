import java.util.*;
public class Verhoeff
{
    Scanner ob=new Scanner(System.in);
    public int isvalidaadhar(long aadhar_no)
    {
        long d[][]={
            {0,1,2,3,4,5,6,7,8,9},
            {1,2,3,4,0,6,7,8,9,5},
            {2,3,4,0,1,7,8,9,5,6},
            {3,4,0,1,2,8,9,5,6,7},
            {4,0,1,2,3,9,5,6,7,8},
            {5,9,8,7,6,0,4,3,2,1},
            {6,5,9,8,7,1,0,4,3,2},
            {7,6,5,9,8,2,1,0,4,3},
            {8,7,6,5,9,3,2,1,0,4},
            {9,8,7,6,5,4,3,2,1,0}
        };
        long p[][]={
            {0,1,2,3,4,5,6,7,8,9},
            {1,5,7,6,2,8,3,0,9,4},
            {5,8,0,3,7,9,6,1,4,2},
            {8,9,1,6,0,4,3,5,2,7},
            {9,4,5,3,1,2,6,8,7,0},
            {4,2,8,6,5,7,3,9,0,1},
            {2,7,9,3,8,0,6,4,1,5},
            {7,0,4,6,9,1,3,2,5,8}
        };
        long inv[]={0,4,3,2,1,5,6,7,8,9};
        int len=String.valueOf(aadhar_no).length();
        if(len!=12)
            return 0;
        long c=0,digit=0,temp=0;
        for(int i=0;i<12;i++)
        {
            digit=aadhar_no%10;
            aadhar_no=aadhar_no/10;
            temp=p[i%8][(int)digit];
            c=d[(int)c][(int)temp];
        }
        if(c==0)
            return 1;
        else
            return 0;
    }
    public void main()
    {
        System.out.println("Enter Aadhar number to be verified : ");
        long code=ob.nextLong();
        if(isvalidaadhar(code)==1)
            System.out.println("Valid");
        else
            System.out.println("Invalid");
    }
}