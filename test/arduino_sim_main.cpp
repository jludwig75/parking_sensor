extern void setup();
extern void loop();


int main(int argc, char *argv[])
{
    setup();

    while(true)
    {
        loop();
    }

    return 0;
}