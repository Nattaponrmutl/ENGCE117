#include <stdio.h>

int KnapsackBT(int *weight_list, int *value_list, int total_items, int max_capacity, int current_index, int *result_array);

int main() {

    int total_items = 5;
    int max_capacity = 11;

    int weight_list[5] = {1,2,5,6,7};
    int value_list[5] = {1,6,18,22,28};

    int *result_array;
    int maximum_value;

    result_array = new int[total_items];

    for(int i=0;i<total_items;i++)
        result_array[i] = 0;

    maximum_value = KnapsackBT(weight_list,value_list,total_items,max_capacity,0,result_array);

    printf("Value = %d\n",maximum_value);

    for(int i=0;i<total_items;i++)
        printf("%d ",result_array[i]);

    delete[] result_array;

    return 0;
}

int KnapsackBT(int *weight_list, int *value_list, int total_items, int max_capacity, int current_index, int *result_array){

    if(current_index == total_items)
        return 0;

    int *array_if_excluded = new int[total_items];
    int *array_if_included = new int[total_items];

    for(int i=0;i<total_items;i++){
        array_if_excluded[i] = 0;
        array_if_included[i] = 0;
    }

    int value_if_excluded =
        KnapsackBT(weight_list,value_list,total_items,max_capacity,current_index+1,array_if_excluded);

    int value_if_included = 0;

    if(max_capacity >= weight_list[current_index]){

        int remaining_capacity = max_capacity - weight_list[current_index];

        value_if_included =
            value_list[current_index] +
            KnapsackBT(weight_list,value_list,total_items,remaining_capacity,current_index+1,array_if_included);
    }

    int highest_value_found;

    if(value_if_included > value_if_excluded){

        highest_value_found = value_if_included;

        for(int i=current_index+1;i<total_items;i++)
            result_array[i] = array_if_included[i];

        result_array[current_index] = 1;

    }
    else{

        highest_value_found = value_if_excluded;

        for(int i=current_index+1;i<total_items;i++)
            result_array[i] = array_if_excluded[i];

        result_array[current_index] = 0;
    }

    delete[] array_if_excluded;
    delete[] array_if_included;

    return highest_value_found;
}
