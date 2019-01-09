import java.math.BigInteger;
import java.util.Scanner;
//Substitute krakovia to Main
public class krakovia {


    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int N = 0, F = 0, cases = 1;
        BigInteger bi = new BigInteger("0");
        while(true){
            bi = BigInteger.ZERO;
            N = scanner.nextInt();
            F = scanner.nextInt();
            if(N == 0 && F == 0)
                break;
            for(int i = 0; i < N; i++){
                bi = bi.add(scanner.nextBigInteger());
            }
            System.out.println("Bill #" + (cases++) + " costs " + bi + ": each friend should pay " + bi.divide(new BigInteger(F + "")) + "\n" );
        }
    }
    
}
