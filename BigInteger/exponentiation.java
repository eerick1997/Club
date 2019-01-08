import java.math.*;
import java.util.*;
//Substitute exponentation to Main
public class exponentiation{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextBigDecimal()){
            BigDecimal R = scanner.nextBigDecimal();
            int n = scanner.nextInt();
            String str = R.pow(n).stripTrailingZeros().toPlainString();
            System.out.println( (str.charAt(0) == '0')? str.substring(1):str );
        }

    }
}