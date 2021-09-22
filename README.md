Template for HPC Project
========================

🚀 HPC Development Ready 🚀

Features
---------

- **Uniform**, **Reproducible** setup of HPC development environment using container
- [CUDA][cuda], [Intel MKL][intel-mkl] integration, and [OpenMP Offloading][openmp-offloading] / [OpenACC][openacc] enabled compilers ([GCC][gcc-openmp-offloading], [Clang][llvm-openmp-offloading]) in a container
- [GitHub Actions][github-actions] with container and [Visual Studio Code][vscode] [Remote Container][remote-container] exntension settings

[ricosjp/allgebra](https://github.com/ricosjp/allgebra) is a project of development containers for HPC developer,
and this repository is its sub-project.

[remote-container]: https://github.com/microsoft/vscode-dev-containers
[vscode]: https://github.com/microsoft/vscode
[github-actions]: https://docs.github.com/en/actions
[cuda]: https://developer.nvidia.com/cuda-toolkit
[intel-mkl]: https://software.intel.com/content/www/us/en/develop/documentation/oneapi-mkl-dpcpp-developer-reference/top.html
[openmp-offloading]: https://www.openmp.org/updates/openmp-accelerator-support-gpus/
[openacc]: https://www.openacc.org/
[gcc-openmp-offloading]: https://gcc.gnu.org/wiki/Offloading
[llvm-openmp-offloading]: https://openmp.llvm.org/index.html

NVIDIA GPU
-----------

### For Linux

Install [docker engine][docker], [docker compose][docker-compose] and [NVIDIA container toolkit][nvidia-container-toolkit]

[docker]: https://docs.docker.com/engine/
[docker-compose]: https://docs.docker.com/compose/
[nvidia-container-toolkit]: https://github.com/NVIDIA/nvidia-docker

### For Windows 11 (CUDA on WSL2)

In order to use CUDA on WSL2, you have to use Windows 11 distributed by [Windows Insider Program][WIP].

- Enable [Windows 10 Insider Program][WIP] with beta channel, and run Windows Update
- Install [NVIDIA Drivers for CUDA on WSL, including DirectML Support](https://developer.nvidia.com/cuda/wsl/download)
- Install [Docker Desktop for Windows](https://hub.docker.com/editions/community/docker-ce-desktop-windows)
  - Use WSL2 mode instead of Hyper-V mode

Then you can run `docker` command on cmd.exe or PowerShell

```
docker run -it --rm --gpus=all ghcr.io/ricosjp/allgebra/cuda11_4/clang12/mkl:21.09.0
```

[WIP]: https://insider.windows.com/

Windows 10 is not supported because we cannot handle NVIDIA GPU managed by Windows from WSL2 without CUDA on WSL2.

### Setup Remote Container Extension

Here, we start setup vscode remote container extension:

- Clone this repository
- Open the cloned directory by [Visual Studio Code][vscode]
- Install [Remote Container][remote-container] extension
- Click the lower left `><` green button in vscode UI
- Select "Reopen in Container"
- Select "From docker-compose.yml"
  - Then the `docker pull` starts. This will download the allgebra container, which is very large (~8GB) because it contains CUDA and Intel MKL binaries.
  - You can see the downloading log in the vscode's terminal
- If everything goes well, a new vscode window opens with Remote Container extension.
  - Run `nvidia-smi` to confirm the GPUs are accessible

### Use host SSH key in container

VSCode will expose host's ssh-agent socket into container process, and you can use host SSH key in container.
See the [official document of vscode](https://code.visualstudio.com/docs/remote/troubleshooting#_setting-up-the-ssh-agent) for detail.
Roughly,

- Start host ssh-agent process
  - In Windows, you can check if ssh-agent starts by `Get-Service ssh-agent`
- `ssh-add` host key to host ssh-agent
  - When the key is correctly added, `ssh-add -l` command shows the registered key.
- (Re)start Remote Container
  - The path of socket connecting to host ssh-agent is written in `$SSH_AUTH_SOCK` env variable
  - `ssh-add -l` command shows the key registerred on the host
