#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double unitPrice;
    int quantity;
    char name[20];
} product_t;

int readFromFile(FILE* inp, product_t* prod);
void display(product_t* prod, int noOfProd);

int
main() {
    FILE* inp = fopen("products.txt", "r");

    if (inp == NULL)
        printf("Error! File counldn't be opened!\n");

    else
    {
        product_t* prod;

        int noOfProd, input = 0, sold = 0;
        double givenMoney, ganined = 0.0;
        fscanf(inp, "%d", &noOfProd);
        

        prod = (product_t*)malloc(noOfProd * sizeof(product_t));

        noOfProd = readFromFile(inp, prod);
        fclose(inp);

        display(prod, noOfProd);

        do {
            
            printf("Enter product number to purchase (to stop -1):");
            scanf("%d", &input);
            
            
            if(input!=-1){
                    if (prod[input].quantity > 0)
                    {
                        printf("The product \"%s\" is choosen, its price is %.2f\n", prod[input].name, prod[input].unitPrice);
                        printf("Insert the money.");
                        scanf("%lf", &givenMoney);
                        
                                if(givenMoney < prod[input].unitPrice)
                                {
                                    printf("Your money is not enough, and returned back\n");
                                }
                                
                                else
                                {
                                    
                                    printf("%.2f TL returned back.\n", prod[input].unitPrice - givenMoney);
                                   
                                    ganined = ganined + (prod[input].unitPrice);
                                    prod[input].quantity--;
                                    sold++;
                                    
                                    display(prod, noOfProd);
                                }

                            }
                    

                    else
                    {
                        printf("THERE IS NO MORE %s\n", prod[input].name);
                        display(prod, noOfProd);

                    }

            }
            
        } while (input > 0 && input < 11);

        if (input == -1){
            printf("Today, %d products sold.\n", sold);
            printf("Total gain is %.2f\n", ganined);
        }
    }
    return 0;
}

int
readFromFile(FILE* inp, product_t* prod)
{
    int i = 1;

    while (!feof(inp)) {
        fscanf(inp, "%lf %d %[^\n]", &(prod + i)->unitPrice, &(prod + i)->quantity, (prod + i)->name);

        i++;
    }

    return i;
}

void
display(product_t* prod, int noOfProd) {
    printf("\tPRODUCT\t\tUNIT PRICE\tQUANTITY\n");
    for (int i = 1; i < noOfProd; i++)
    {
        printf("%d %15.15s \t %-.2f \t\t%d \n", i, prod[i].name, prod[i].unitPrice, prod[i].quantity);
    }
}
