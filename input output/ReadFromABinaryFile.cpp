#include <fstream>
#include <iterator>
#include <algorithm>

int main()
{
    std::ifstream input( "C:\\Final.gif", std::ios::binary );
    std::ofstream output( "C:\\myfile.gif", std::ios::binary );

    std::copy( 
        std::istreambuf_iterator<char>(input), 
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(output));
}
