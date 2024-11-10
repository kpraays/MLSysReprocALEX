## Who did it?
It was a collaboration between: Aayush Kapur and Rahma Nouji

## Repo structure:
- ALEX: contains the cloned repo for ALEX from Microsoft.
- artifacts: plots, latex files, report pdf and supporting docs.

- run: it contains the code we wrote to run ALEX on our systems and generate plots/ results.
    - (move run to ALEX if there is issue in calling scripts)
  
- Feel free to change the repo structure however you see fit.

## Note on workflow:
(please correct me if there is something wrong)
- We read the paper. Make our notes.
- Run ALEX in different environments: mimi and locally
- Pick 3 plots to be created. These plots have to be generated for baseline and for ALEX on different testing environments.
- Write explanation for why we are getting the plots we are getting.

- make notes, write stuff in google doc: once we complete every thing, we will put it in separate files under artifacts so that it is properly organized.

## Where to access files for creating reports and sharing information?
- Report will be created on overleaf: **link to edit** [https://www.overleaf.com/8618816293qmppjpyyvgsm#353b0b](https://www.overleaf.com/8618816293qmppjpyyvgsm#353b0b)

- Google doc to share information amongst each other: [google doc](https://docs.google.com/document/d/1UJQppZ9PtSxbBmIPvyNXJNvlhyqjbDh9T2Zvztn0WM0/edit?usp=sharing)

- Put the files/ pdfs/ external things which you find interesting in artifacts folder.

- Final plots to be used in the report will go in overleaf. Rest of them can be kept in artifacts with their own directory.

## Doubts
Why are the dataset files 1.5GB when in the paper they mention the file size as 15GB/ 3GB?

Do we need to do grid search for determining the parameters to get the optimum throughput?

Is there any specific framework using which we have to record the benchmarks and create the visualisation?


Context: We are trying to run ALEX and b+tree as baseline.

How is the YCSB dataset's payload coming out to be 80 bytes? I thought the main.cpp is generating random payload for each key coming from dataset. Do we modify the data type for the payload to make it 80 bytes? In the paper they mentioned using 80 bytes payload for the YCSB workload.

Where did you configure the node sizes for b+ tree?

How did you pick the batch size to get the highest throughput while creating measurements? I am referring to the batch size used for lookups/ insertion ratio after bulk loading under main.cpp of benchmark file?


