#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iomanip>


void tikrinam_simboliuka (char a, char b, char ka_tikrinam)
{
    while(!std::cin || ka_tikrinam!= a && ka_tikrinam!= b )
        {
            std::cout<<"Ivestas netinkamas dydis, pasirinkite 1 ar 2: ";
            std::cin>>ka_tikrinam;

            if(ka_tikrinam== a || ka_tikrinam== b )
            {
                break;
            }
        }
}

std::string hash_function(std::string str)
{
    int hash_length = 64;
    std::string result;
    std::string default_str = "O Fortuna velut luna statu variabilis, semper crescis aut dec...";
    std::string copy = default_str;
    

    if(str.empty())
    {
        for(int i = 0; i < hash_length; i++)
        {
            int a = 0;
                do
                {
                    a++;
                    copy[i] = (((copy[i] + a*i + a) ^ ((default_str[i] ^ i) + a)) & (default_str[(i * a - 1 * ~(i*a))%hash_length] + ~a)) % 128;
                } while ((copy[i] < '0' || copy[i] > '9') && (copy[i] < 'a' || copy[i] > 'f'));
        }
    }
    else
    {
        
        for(int i = 0; i < str.length(); i++)
        {
            for(int j = 0; j < hash_length; j++)
            {
                int a = 0;
                do
                {
                    a++;
                    copy[j] = (str[i] * str[i] + copy[j] + a + i * j * a + (copy[a * i % hash_length] * default_str[j]) ^ (str[a % str.length()] * copy[3])) % 128;
                } while ((copy[j] < '0' || copy[j] > '9') && (copy[j] < 'a' || copy[j] > 'f'));
            }
        }
    }
    
    
    return copy;
    
}
void read_file()
{
    std::string file;
    std::cout << "Iveskite failo, is kurio skaitysime, pavadinima: ";
    std::cin >> file;
    std::cout << std::endl;
    std::ifstream in (file.c_str());

        try
        {
            std::string exc = "Skaitymo failas neegzistuoja";
            if(in) std::cout << "skaitymo failas egzistuoja" << std::endl;
            else throw(exc);
        }
        catch(std::string exc)
        {
            std::cout << exc << std::endl;
            return;
        }

    std::cout << "Darysime viso failo hasha (1) ar kiekvienos eilutes (2)?: ";
    char ka_daryt;
    std::cin >> ka_daryt;
    tikrinam_simboliuka('1', '2', ka_daryt);


    std::string ojojoj;

    if(ka_daryt == '2')
    {
        std::string spausdinam;
        auto tmp = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sum = tmp - tmp;
        //std::string input;
        while(!in.eof())
        {
            std::getline(in, ojojoj);
            auto start = std::chrono::high_resolution_clock::now();
            spausdinam = hash_function(ojojoj); 
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            sum += diff;
            //input += ojojoj;
            std::cout << spausdinam <<"\n";
        }
        std::cout << "Hashavimas uztruko laiko: " << sum.count() << " s\n";
        
        //std::cout << hash_function(input);  
    }

    else
    {
        std::string input;
        while(!in.eof())
        {
            std::getline(in, ojojoj);
            input += ojojoj;
        }
        
        std::cout << "Gautas hash'as: " << hash_function(input) << "\n";  
    }

     
}



std::string HexToBin(char hexdec) 
{ 
    long int i = 0; 
  
    while (hexdec) { 
  
        switch (hexdec) { 
        case '0': 
            return "0000"; 
            break; 
        case '1': 
            return "0001"; 
            break; 
        case '2': 
            return "0010"; 
            break; 
        case '3': 
            return "0011"; 
            break; 
        case '4': 
            return "0100"; 
            break; 
        case '5': 
            return "0101"; 
            break; 
        case '6': 
            return "0110"; 
            break; 
        case '7': 
            return "0111"; 
            break; 
        case '8': 
            return "1000"; 
            break; 
        case '9': 
            return "1001"; 
            break; 
        case 'A': 
        case 'a': 
            return "1010"; 
            break; 
        case 'B': 
        case 'b': 
            return "1011"; 
            break; 
        case 'C': 
        case 'c': 
            return "1100"; 
            break; 
        case 'D': 
        case 'd': 
            return "1101"; 
            break; 
        case 'E': 
        case 'e': 
            return "1110"; 
            break; 
        case 'F': 
        case 'f': 
            return "1111"; 
            break; 
        default: 
            std::cout << "\nInvalid hexadecimal digit ";
        } 
    } 
} 

void generuojam(const int len)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(48, 122);


    std::ofstream fd;
    fd.open("dive1.txt", std::ios_base::app);
    {
        for(int i = 0; i< len; ++i)
            fd << (char) distrib(gen);
    }
    fd.close();
}

std::string rand_str(const int len)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(48, 122);

    std::string tmp_s;
    

    for(int i = 0; i< len; i++)
         tmp_s += (char)distrib(gen);
    return tmp_s;
}


char rand_strCHAR()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(48, 122);

  
    char tmp_c;


 tmp_c = (char) distrib(gen);
return tmp_c;
}

void collision_test (const int len)
{
    
  unsigned int repeats = 0;
    std::string t1; // = "abc";
    std::string t2; //= "bca";
    std::string h1;
    std::string h2;
  for (int i = 0; i < 25000; i++)
  {
      do
    {
        t1 = rand_str(len);
    } while (t1 == t2);;
    do
    {
        t2 = rand_str(len);
    } while (t1 == t2);
    

    h1 = hash_function(t1);
    h2 = hash_function(t2);
    if (h1 == h2)
    {
          repeats++;
    }
  }
  std::cout << "length: " << len << " repeats ->  " << repeats << std::endl;
}

void  collision_test2(const int len)
{
    std::cout << "Skirtinguma vertinsime bitu (b) ar hexu (h) lygmenyje?\n";
      char kas;
      std::cin >> kas;
    tikrinam_simboliuka('b', 'h', kas);
      
      
    const int prasisukimo_ilgis = 25000; 
    std::string t1; 
    std::string t2;
    std::string tmp;
    std::string h1;
    std::string h2;
    std::string hash_bin1, hash_bin2;
    int bit_min = 256, bit_max = 0, sum = 0;
    int hex_min = 64, hex_max = 0;

  for (size_t i = 0; i != prasisukimo_ilgis; ++i)
  {
    
    do
    {
        t1 = rand_str(len);
    } while (t1 == tmp);

    t2 = t1;
    tmp = t1;

    do
    {
        t1[2] = rand_strCHAR();
    } while (t1[2] == t2[2]);

    h1 = hash_function(t1);
    h2 = hash_function(t2);

    if(kas == 'b')
    {
        int tmpsum = 0;
        for(int j = 0; j < 64; j++)
        {
            hash_bin1 = HexToBin(h1[j]);
            hash_bin2 = HexToBin(h2[j]);

            for(int z = 0; z < 4; z++)
            {
                if(hash_bin1[z] != hash_bin2[z])
                {
                    tmpsum++;
                }
            }
        }
        if(tmpsum < bit_min)
        {
            bit_min = tmpsum;
        }
        if(tmpsum > bit_max)
        {
            bit_max = tmpsum;
        } 
        sum += tmpsum;
    }

    else
    {
        int tmpsum = 0;
        for(int j = 0; j < 64; j++)
        {
            if(h1[j] != h2[j])
            {
                tmpsum++;
            }
        }
        if(tmpsum < hex_min)
        {
            hex_min = tmpsum;
        }
        if(tmpsum > hex_max)
        {
            hex_max = tmpsum;
        }
        sum += tmpsum;
    }

}
    if(kas == 'b')
    {
        std::cout << "Maziausias skirtingumas procentais: " << std::fixed << std::setprecision(2) << (double) bit_min * 100 / 256 << "%\n";
        std::cout << "Didziausias skirtingumas procentais: " << (double) bit_max * 100 / 256 << "%\n";
        std::cout << "Vidutinis skirtingumas procentais: " << (double) sum / prasisukimo_ilgis * 100 / 256 << "%\nBitu lygmenyje\n";
    }

    else
    {
        std::cout << "Maziausias skirtingumas procentais: " << std::fixed << std::setprecision(2) << (double) hex_min * 100 / 64 << "%\n";
        std::cout << "Didziausias skirtingumas procentais: " << (double) hex_max * 100 / 64 << "%\n";
        std::cout << "Vidutinis skirtingumas procentais: " << (double) sum / prasisukimo_ilgis * 100 / 64 << "%\nHexu lygmenyje\n";
    }
}

void interface ()
{
    std::cout <<
"Ka veiksime?\n1) Tiesiog skaiciuosime ranka suvesta arba nuskaityta is failo hasha? (1)\n2) Atliksime tyrimus (2)\n3) Generuosime nauja faila (3)";
    char ka_veikiam;
    std::cin >> ka_veikiam;
    while(!std::cin || ka_veikiam!= '1' && ka_veikiam!= '2'  && ka_veikiam != '3')
    {
        std::cout<<"Ivestas netinkamas dydis, pasirinkite 1, 2 ar 3: ";
        std::cin>>ka_veikiam;

        if(ka_veikiam== '1' || ka_veikiam== '2' || ka_veikiam == '3' )
        {
            break;
        }
    }

    if(ka_veikiam == '1')
    {
        std::cout << "Inputa skaitysim is failo (f) ar irasysim ranka (r)?";
        char kaip;
        std::cin >> kaip;
        tikrinam_simboliuka('f', 'r', kaip);

        if (kaip == 'r')
        {
            std::cout << "Input: ";
            std::string input;
            std::getline(std::cin >> std::ws, input);
            std::cout << hash_function(input);
        }

        else read_file();
    }

    else if(ka_veikiam == '3')
    {
        generuojam(1001);
    }
    
    else
    {
        std::cout << "Darysime eksperimentini tyrima apzvelgdami 4-5 punktus (1) ar apzvelgdami 6 punkta (2)? ";
        char koks_tyrimas;
        std::cin >> koks_tyrimas;

        tikrinam_simboliuka('1', '2', koks_tyrimas);

        if(koks_tyrimas == '1')
        {
            std::cout << "Iveskite random simboliu kieki: ";
            int ilgis;
            std::cin >> ilgis; 
            collision_test(ilgis);
        }

        else
        {
            std::cout << "Iveskite random simboliu kieki: ";
            int ilgis;
            std::cin >> ilgis; 
            collision_test2(ilgis);
        }
    }
}