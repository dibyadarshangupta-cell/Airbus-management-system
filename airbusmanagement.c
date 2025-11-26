#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flight {
    int flight_no;
    char source[50];
    char destination[50];
    int seats;
};

struct Booking {
    int flight_no;
    char passenger_name[50];
};

void addFlight() {
    struct Flight f;
    FILE *fp = fopen("flights.dat", "ab");

    printf("\nEnter Flight Number: ");
    scanf("%d", &f.flight_no);

    printf("Enter Source: ");
    scanf("%s", f.source);

    printf("Enter Destination: ");
    scanf("%s", f.destination);

    printf("Enter Available Seats: ");
    scanf("%d", &f.seats);

    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);

    printf("\nFlight Added Successfully!\n");
}

void viewFlights() {
    struct Flight f;
    FILE *fp = fopen("flights.dat", "rb");

    printf("\n---- ALL FLIGHTS ----\n");
    while (fread(&f, sizeof(f), 1, fp)) {
        printf("Flight No: %d | %s --> %s | Seats: %d\n",
               f.flight_no, f.source, f.destination, f.seats);
    }
    fclose(fp);
}

void searchFlight() {
    int num;
    struct Flight f;
    int found = 0;

    FILE *fp = fopen("flights.dat", "rb");

    printf("\nEnter Flight Number to Search: ");
    scanf("%d", &num);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.flight_no == num) {
            printf("\nFlight Found!\n");
            printf("Flight No: %d\nSource: %s\nDestination: %s\nSeats: %d\n",
                   f.flight_no, f.source, f.destination, f.seats);
            found = 1;
        }
    }
    if (!found)
        printf("\nFlight Not Found!\n");

    fclose(fp);
}

void bookTicket() {
    int num, found = 0;
    struct Flight f;
    struct Booking b;

    FILE *fp = fopen("flights.dat", "rb+");

    printf("\nEnter Flight Number to Book: ");
    scanf("%d", &num);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.flight_no == num) {
            found = 1;

            if (f.seats > 0) {
                f.seats--;

                fseek(fp, -sizeof(f), SEEK_CUR);
                fwrite(&f, sizeof(f), 1, fp);

                FILE *bp = fopen("bookings.dat", "ab");
                b.flight_no = num;

                printf("Enter Passenger Name: ");
                scanf("%s", b.passenger_name);

                fwrite(&b, sizeof(b), 1, bp);
                fclose(bp);

                printf("\nTicket Booked Successfully!\n");
            } else {
                printf("\nNo Seats Available!\n");
            }
            break;
        }
    }

    if (!found)
        printf("\nFlight Not Found!\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n====== AIRBUS MANAGEMENT SYSTEM ======\n");
        printf("1. Add Flight\n");
        printf("2. View All Flights\n");
        printf("3. Search Flight\n");
        printf("4. Book Ticket\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addFlight(); break;
            case 2: viewFlights(); break;
            case 3: searchFlight(); break;
            case 4: bookTicket(); break;
            case 5: exit(0);
            default: printf("Invalid Choice! Try Again.\n");
        }
    }

    return 0;
}