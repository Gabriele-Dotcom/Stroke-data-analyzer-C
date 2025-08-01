#include <stdio.h>
#include <stdbool.h>

typedef struct Data {
    int id;
    char gender[5];
    int age;
    int hypertension;
    int heart_disease;
    char ever_married[3];
    char work_type[100];
    char residence_type[100];
    float avg_glucose_level;
    float bmi;
    char smoking_status[100];
    int stroke;
}Data;

//parses data inside the struct, returns true if it has success, otherwise false
bool parse_data(Data data[], FILE *filePtr) {
    char buffer[150];
    bool parsed = false;
    if(fgets(buffer, 150, filePtr) == NULL) {
        printf("Error reading the file");
        return parsed;
    } else {
        parsed = true;
        int i = 0;
        while(fgets(buffer, 150, filePtr) != NULL) {
            //iteratively stores retrieved data inside the struct's fields for all the lines
            sscanf(buffer, "%d, %6[^,], %d, %d, %d, %3[^,], %20[^,], %10[^,], %f, %f, %20[^,], %d", &data[i].id, data[i].gender, &data[i].age, &data[i].hypertension, &data[i].heart_disease, data[i].ever_married, data[i].work_type, data[i].residence_type, &data[i].avg_glucose_level, &data[i].bmi, data[i].smoking_status, &data[i].stroke);
            i++;
        }
    }
    return parsed;
}

//calculates the average age of ALL the patients
int average_age(Data data[]) {
    int average = 0;
    int i = 0;
    while(data[i].age != 0) {
        average += data[i].age;
        i++;
    }
    average = average/i;
    return average;
}

//calculates the percentage of patients that had a stroke
int stroke_percentage(Data data[]) {
    int stroke = 0;
    int i = 0;
    while(data[i].id != 0) {
        stroke += data[i].stroke;
        i++;
    }
    int result = (float)stroke/i * 100;
    return result;
}

//calculates the percentage of high BMI patients that had a stroke
int High_BMI(Data data[]) {
    int BMI = 0;
    int i = 0;
    while(data[i].id != 0) {
        if(data[i].bmi > 25 && data[i].stroke == 1) {
            BMI++;
        }
        i++;
    }
    int result = (float)BMI/i * 100;
    return result;
}

int main() {
    FILE *filePtr = fopen("healthcare-dataset-stroke-data.csv", "r");
    if(filePtr == NULL) {
        printf("Failure to open file");
        return 1;
    } else {
        //creating a new struct
        Data data[6000];
        // parse_data returns true if the parsing is successful
        if(parse_data(data, filePtr)) {
            printf("Parsing successful\n");
        }
        printf("The average age is %d years old\n", average_age(data));
        printf("The percentage of patients with a stroke is %d%%\n", stroke_percentage(data));
        printf("%d%% of the patients with a high BMI had a stroke", High_BMI(data));
    }
}