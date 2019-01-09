import java.math.*;
import java.util.*;

public class HighPrecisionNumber{

    public static void main(String args[]){
        BigDecimal result = new BigDecimal("0.0");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
    
        for(int i = 0; i < n; ){
            BigDecimal number = scanner.nextBigDecimal();
            if(number.equals(BigDecimal.ZERO)){
                System.out.println(result.stripTrailingZeros().toPlainString());
                result = BigDecimal.ZERO;
                i++;
            } else {
                result = result.add(number);
            }
        }
    }
}