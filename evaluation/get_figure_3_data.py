#!/usr/bin/python3
from argparse import ArgumentParser
from operator import itemgetter
import json

def main():
    ap = ArgumentParser()
    ap.add_argument('data_file')
    ap.add_argument('json_file')
    args = ap.parse_args()

    with open(args.data_file) as fp:
        reader = json.load(fp)
        program_improvement = [
            (row['program'],
             float(row['x_more_easy_to_transform_macros_we_find_than_mennie']))
            for row in reader
        ]

        total_improvement = program_improvement.pop()[1]

        program_improvement.sort(key=itemgetter(1), reverse=True)
        program_improvement.append(('Total', total_improvement))
        
        json_data = []
        for program, improvement in program_improvement:
            json_data.append({'Program': program, 'How times more easily portable macros Maki finds over prior work': improvement})
        
        print(json.dumps(json_data, indent=4))
        
        with open(f'{args.json_file}.json', 'w') as fp:
            json.dump(json_data, fp)

if __name__ == '__main__':
    main()
