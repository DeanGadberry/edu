// Chapter 12 notes

/*
    fstream data type:
        fstreamobject.open("file name", file access flag);
        dataFile.open("info.txt", ios::out);

    File Access Flags:
    =>  ios::app
                ==>append mode
    =>  ios::ate
                ==>go to end of file
    =>  ios::binary
                ==>data written in pure binary
    =>  ios::in
                ==>read data (no file, no open)
    =>  ios::out
                ==>write data (overwrites)
    =>  ios::trunc
                ==>delete (default mode used by ios::out)
    {use | between multiple flags}
    file.open("myfile.txt", ios::in | ios::out);
     this will create a new file, or preserve one to be written to 
    ofstream and ifstream may recieve access flags to determine the way in which the default operation should be observed.

    


    
*/

int main() 
{

}
