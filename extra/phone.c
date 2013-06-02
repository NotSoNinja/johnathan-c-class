#include <string.h>
#include <stdio.h>

typedef struct phone {
	char nickname[80];
	char name[80];
	char phone[15];
	char email[80];
} phoneRecord;



int main(int argc, char **argv) {
	phoneRecord records[2];
	int i;

	strcpy(records[0].nickname, "matt");
	strcpy(records[0].name, "Matt Harris");
	strcpy(records[0].phone, "406 223 4225");
	strcpy(records[0].email, "matthaeus.harris@gmail.com");

	strcpy(records[1].nickname, "johnathan");
	strcpy(records[1].name, "Johnathan Adams");
	strcpy(records[1].phone, "650 646 8614");
	strcpy(records[1].email, "jwaohnathan@gmail.com");

	if (argc == 1) {
		printf("Usage:  %s nickname\n", argv[0]);
		return -1;
	} else if (argc == 2) {
		for (i = 0; i < sizeof(records) / sizeof(phoneRecord); i++) {
			if (strcmp(argv[1], records[i].nickname) == 0) {
				printf("Name: %s\nPhone: %s\nEmail: %s\n", records[i].name, records[i].phone, records[i].email);
				break;
			}
		}
	}
	return 0;
}