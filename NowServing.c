#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentNumber = 0;

void serveNextNumber() {
    currentNumber++;
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<script>window.location.href = \"now_serving.html\";</script>");
    printf("</head>");
    printf("<body>");
    printf("</body>");
    printf("</html>");
}

int main() {
    char *requestData = getenv("QUERY_STRING");
    
    if (requestData != NULL) {
        char *nextParam = strtok(requestData, "&");
        
        while (nextParam != NULL) {
            char paramName[50], paramValue[50];
            sscanf(nextParam, "%[^=]=%s", paramName, paramValue);
            
            if (strcmp(paramName, "action") == 0 && strcmp(paramValue, "next") == 0) {
                serveNextNumber();
                break;
            }
            
            nextParam = strtok(NULL, "&");
        }
    }
    
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<meta http-equiv=\"refresh\" content=\"5\">");
    printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"styles.css\">");
    printf("</head>");
    printf("<body>");
    printf("<h2>Current Number: %d</h2>", currentNumber);
    printf("<a href=\"now_serving.html?action=next\"><button>Next</button></a>");
    printf("</body>");
    printf("</html>");
    
    return 0;
}
int main() {
    char *requestData = getenv("QUERY_STRING");

    // If there is a query string
    if (requestData != NULL) {
        char *nextParam = strtok(requestData, "&");
        
        // Check each parameter in the query string
        while (nextParam != NULL) {
            char paramName[50], paramValue[50];
            sscanf(nextParam, "%[^=]=%s", paramName, paramValue);
            
            // Check if the action parameter is 'next'
            if (strcmp(paramName, "action") == 0 && strcmp(paramValue, "next") == 0) {
                serveNextNumber();
                exit(0);
            }
            
            nextParam = strtok(NULL, "&");
        }
        
        // If the action parameter is missing or invalid
        printf("Content-Type: text/html\n\n");
        printf("<html>");
        printf("<head>");
        printf("<title>Error</title>");
        printf("</head>");
        printf("<body>");
        printf("<h1>Error: Invalid Request</h1>");
        printf("</body>");
        printf("</html>");
    }

    // If there is no query string
    else {
        // Increment the current number
        currentNumber++;
        
        // Open the file for writing
        FILE *fptr = fopen("current_number.txt", "w");
        
        // If the file could not be opened
        if (fptr == NULL) {
            printf("Content-Type: text/html\n\n");
            printf("<html>");
            printf("<head>");
            printf("<title>Error</title>");
            printf("</head>");
            printf("<body>");
            printf("<h1>Error: Unable to Open File</h1>");
            printf("</body>");
            printf("</html>");
        }
        
        // If the file was successfully opened
        else {
            // Print the current number to the file
            fprintf(fptr, "%d", currentNumber);
            
            // Close the file
            fclose(fptr);
            
            // Reload the page with the updated current number
            printf("Content-Type: text/html\n\n");
            printf("<html>");
            printf("<head>");
            printf("<script>window.location.href = \"now_serving.html\";</script>");
            printf("</head>");
            printf("<body>");
            printf("</body>");
            printf("</html>");
        }
    }
    
    return 0;
}

void serveNextNumber() {
    // Open the file for reading
    FILE *fptr = fopen("current_number.txt", "r");
    
    // If the file could not be opened
    if (fptr == NULL) {
        printf("Content-Type: text/html\n\n");
        printf("<html>");
        printf("<head>");
        printf("<title>Error</title>");
        printf("</head>");
        printf("<body>");
        printf("<h1>Error: Unable to Open File</h1>");
        printf("</body>");
        printf("</html>");
    }
    
    // If the file was successfully opened
    else {
        // Read the current number from the file
        fscanf(fptr, "%d", &currentNumber);
        
        // Close the file
        fclose(fptr);
        
        // Increment the current number
        currentNumber++;
        
        // Open the file for writing
        fptr = fopen("current_number.txt", "w");
        
        // If the file could not be opened
        if (fptr == NULL) {
            printf("Content-Type: text/html\n\n");
            printf("<html>");
            printf("<head>");
            printf("<title>Error</title>");
            printf("</head>");
            printf("<body>");
            printf("<h1>Error: Unable to Open File</h1>");
            printf("</body>");
            printf("</html>");
        }
        
        // If the file was successfully opened
        else {
            // Print the current number to the file
            fprintf(fptr, "%d", currentNumber);
            
            // Close the file
            fclose(fptr);
            
            // Reload the page with the updated current number
            printf("Content-Type: text/html\n\n");
            printf("<html>");
            printf("<head>");
            printf("<script>window.location.href = \"now_serving.html\";</script>");
            printf("</head>");
            printf("<body>");
            printf("</body>");
            printf("</html>");
        }
    }
}