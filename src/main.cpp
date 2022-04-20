#include <iostream>
using namespace std;

void c_system(string cmd) {
    // introducing c_system: it does all the dirty conversion work for you
    system(cmd.c_str());
}

int main(int argc, char** argv)
{
    string gdSongFolder = "GeometryDash";
    if (argc == 1) {
        cout << "Please use the song manager by clicking on a .gdsong file..." << endl;
        system("pause");

    } else {
        string songLocation = argv[1];

        // and now: the code i just copied from stackoverflow
        // https://stackoverflow.com/a/14266139


        string songID = songLocation.substr(0, songLocation.find("."));
        /*                                             ^ might have to change this up,
                                                         since folders can have . in them
                                                         but WHATEVER WHO CARES LMAOOOOO
                                                                                            */

        string splitChars = "\\";
        string curr;
        size_t pos = 0;

        while ((pos = songID.find(splitChars)) != string::npos) {
            curr = songID.substr(0, pos);
            songID.erase(0, pos + splitChars.length());
        }
        // then we will end up with just the song ID, that's it ^o^

        cout << "Installing " << songLocation << " @ " << songID << " ..." << endl;
        cout << "=============================================================================" << endl;

        c_system("copy " + songLocation + " %localappdata%\\GeometryDash /Y"); // copy the song, use overwrite flag
        c_system("del %localappdata%\\GeometryDash\\" + songID + ".mp3 > nul"); // delete old song if it exists
        c_system("rename %localappdata%\\GeometryDash\\" + (songID + ".gdsong") + " " + (songID + ".mp3")); // finally, rename the song

        cout << "=============================================================================" << endl;
        cout << "Song has (probably) been installed. Re-enter the level/restart GD if needed" << endl;
        cout << "This window will close in a couple of seconds, goodbye ..." << endl;

        system("ping 127.0.0.1 -n 5 > nul"); // wait a little bit by doing it the good 'ol script kiddie method
    }
    return 0;
}
