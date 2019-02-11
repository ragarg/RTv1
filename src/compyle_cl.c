#include "rtv1.h"
#include <stdio.h>

#ifdef __APPLE__
# include <OpenCL/opencl.h>
#else
# include <CL/cl.h>
#endif

void read_cl(char **source_str, size_t *source_size)
{
	int fd;

	fd = open("render_pixel.cl", O_RDONLY);
	if (!fd) {
		ft_putstr_fd("Failed to load kernel.\n", 2);
		exit(1);
	}
	*source_str = (char*)malloc(MAX_SOURCE_SIZE);
	*source_size = read(fd, *source_str, MAX_SOURCE_SIZE);
	close(fd);
}

void free_cl(t_cl **cl_ptrs)
{
	(*cl_ptrs)->ret = clFlush((*cl_ptrs)->command_queue);
	(*cl_ptrs)->ret = clFinish((*cl_ptrs)->command_queue);
	(*cl_ptrs)->ret = clReleaseKernel((*cl_ptrs)->kernel);
	(*cl_ptrs)->ret = clReleaseProgram((*cl_ptrs)->program);
	(*cl_ptrs)->ret = clReleaseMemObject((*cl_ptrs)->b_mem_obj);
	(*cl_ptrs)->ret = clReleaseMemObject((*cl_ptrs)->a_mem_obj);
	(*cl_ptrs)->ret = clReleaseCommandQueue((*cl_ptrs)->command_queue);
	(*cl_ptrs)->ret = clReleaseContext((*cl_ptrs)->context);
	free(*cl_ptrs);
}

void cl_init(t_cl *cl_ptrs, t_sphere *spheres, t_ligth lights, char *source_str, size_t source_size, t_sdl *sdl)
{
	cl_ptrs->ret = clGetPlatformIDs(1, &(cl_ptrs->platform_id), &(cl_ptrs->ret_num_platforms));
	cl_ptrs->ret = clGetDeviceIDs(cl_ptrs->platform_id, CL_DEVICE_TYPE_GPU, 1,
								  &(cl_ptrs->device_id), &(cl_ptrs->ret_num_devices));
	cl_ptrs->context = clCreateContext( NULL, 1, &(cl_ptrs->device_id), NULL, NULL, &(cl_ptrs->ret));
	cl_ptrs->command_queue = clCreateCommandQueue(cl_ptrs->context, cl_ptrs->device_id, 0, &(cl_ptrs->ret));
	cl_ptrs->b_mem_obj = clCreateBuffer(cl_ptrs->context, CL_MEM_READ_WRITE,
										sdl->img.h * sdl->img.w * sizeof(unsigned int), NULL, &(cl_ptrs->ret));
	cl_ptrs->a_mem_obj = clCreateBuffer(cl_ptrs->context, CL_MEM_READ_ONLY,
										sizeof(t_sphere), NULL, &(cl_ptrs->ret));
	cl_ptrs->c_mem_obj = clCreateBuffer(cl_ptrs->context, CL_MEM_READ_ONLY,
										sizeof(t_light), NULL, &(cl_ptrs->ret));
	cl_ptrs->ret = clEnqueueWriteBuffer(cl_ptrs->command_queue, cl_ptrs->a_mem_obj, CL_TRUE, 0,
										sizeof(t_sphere) , spheres, 0, NULL, NULL);
	cl_ptrs->ret = clEnqueueWriteBuffer(cl_ptrs->command_queue, cl_ptrs->a_mem_obj, CL_TRUE, 0,
										sizeof(t_light), lights, 0, NULL, NULL);
	cl_ptrs->program = clCreateProgramWithSource(cl_ptrs->context, 1,
												 (const char **)&source_str, (const size_t *)&source_size, &(cl_ptrs->ret));
	cl_ptrs->ret = clBuildProgram(cl_ptrs->program, 1, &(cl_ptrs->device_id), NULL, NULL, NULL);
	cl_ptrs->kernel = clCreateKernel(cl_ptrs->program, "render_pixel", &(cl_ptrs->ret));
	cl_ptrs->ret = clSetKernelArg(cl_ptrs->kernel, 0, sizeof(cl_mem), (void *)&(cl_ptrs->b_mem_obj));
	cl_ptrs->ret = clSetKernelArg(cl_ptrs->kernel, 1, sizeof(cl_mem), (void *)&(cl_ptrs->a_mem_obj));
	cl_ptrs->ret = clSetKernelArg(cl_ptrs->kernel, 2, sizeof(cl_mem), (void *)&(cl_ptrs->c_mem_obj));
}

int	render(t_sdl *sdl, int *x)
{
	t_cl *cl_ptrs;

	cl_ptrs = (t_cl *)malloc(sizeof(t_cl));
	char *source_str = NULL;
	size_t source_size = 0;

	read_cl(&source_str, &source_size);
	cl_init(cl_ptrs, x, source_str, source_size, sdl);
	cl_ptrs->global_item_size = sdl->img.h * sdl->img.w * 2;
	cl_ptrs->ret = clEnqueueNDRangeKernel(cl_ptrs->command_queue, cl_ptrs->kernel, 1, NULL,
										  &(cl_ptrs->global_item_size), NULL, 0, NULL, NULL);
	cl_ptrs->ret = clEnqueueReadBuffer(cl_ptrs->command_queue, cl_ptrs->b_mem_obj, CL_TRUE, 0,
									   sdl->img.h * sdl->img.w * sizeof(unsigned int), sdl->img.img, 0, NULL, NULL);
	free_cl(&cl_ptrs);
	return 0;
}