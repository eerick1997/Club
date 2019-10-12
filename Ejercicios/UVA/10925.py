import sys

def main():
    BillNumber = 1
    while True:
        sum = 0
        values = [ int(i) for i in input().split() ]
        if ( int(values[ 0 ]) == 0 and int(values[ 1 ]) == 0):
            break

        for i in range( int( values[ 0 ] ) ):
            sum += int( input() )
        
        print("Bill #{} costs {}: each friend should pay {}".format(BillNumber, sum, int(sum // values[ 1 ]) ))
        print()
        BillNumber += 1

if __name__ == '__main__':
    main()