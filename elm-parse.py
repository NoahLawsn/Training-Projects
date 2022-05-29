import csv

'''
Web-scraper to pull .xlsx file from ELM and convert to .csv --add here--
'''

infile = open('OPENSEATS.csv', 'r')
outfile = open('Recent Pull.csv', 'w', newline='')
wishlist = open('Wishlist.csv', 'r')
INPUT = csv.reader(infile)
OUTPUT = csv.writer(outfile)
WL = csv.reader(wishlist)
banner_line = 5
filters = []
output_data = []

# Getting information on what to look for: Wishlist item or Keyword search
choice = input("\n1. Search with Keywords\n2. Search Using a Wishlist\n>>  ")
if (choice == '1'):
    filters = input("\n\nExample: neta,comp,cybr,prog,netw\nEnter Keywords to look for separated by commas.\n>> ")
    filters = filters.split(',')        #['neta', 'comp', 'prog', 'sec']
if (choice =='2'):
    for row in WL:
        filters.append(row[0])          #only pulls data of index selected to search each line  #['neta', 'comp', 'prog', 'sec']
# Comparison of Filter data and OPENSEATS.csv data
for row in INPUT:
    if (banner_line > 0):
        print(row)                      #shows each row of banner
        output_data.append(row)
        banner_line = banner_line - 1
    else:
        for course in filters:
            for item in row:
                if course in item:
                    print(row)          #shows each row of matched classes
                    output_data.append(row)

OUTPUT.writerows(output_data)
infile.close()
outfile.close()
wishlist.close()
