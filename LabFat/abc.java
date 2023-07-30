public class abc {
    public static int boothMultiply(int multiplier, int multiplicand) {
        int product = 0;
        int m = multiplier;
        int q = multiplicand;
        int accumulator = 0;

        for (int i = 0; i < 32; i++) {
            if ((q & 1) == 1) {
                accumulator += m;
            }

            m = m << 1;
            q = q >> 1;
        }

        product = accumulator;

        return product;
    }

    public static void main(String[] args) {
        int multiplier = 11;
        int multiplicand = 15;

        int result = boothMultiply(multiplier, multiplicand);
        System.out.println("Result: " + result);
    }
}
