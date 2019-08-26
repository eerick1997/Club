#import<Foundation/Foundation.h>

int main(int argc, const char *argv[]){
    NSAutoRelesePool *pool = [[NSAutoRelesePool alloc] init];
    NSLog(@"Hello world!");
    [pool drain]
    return 0;
}