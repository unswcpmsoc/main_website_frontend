<script lang="ts">
    import ArrowUpRight from 'phosphor-svelte/lib/ArrowUpRight'

    const APPLY_URL = 'https://forms.gle/7kfwtajHtwkcbbak8'

    let { data } = $props()
</script>

<svelte:head>
    <title>Weekly Talks Speaker Applications | UNSW CPMSoc</title>
    <meta
        name="description"
        content="CPMSoc is running weekly undergraduate mathematics talks in Term 1 2027. Speaker applications are open to anyone with a piece of maths to share."
    />
</svelte:head>

<div class="relative w-full overflow-hidden bg-[#141414] text-white">
    <svg class="pointer-events-none absolute inset-0 h-full w-full opacity-[0.12]" aria-hidden="true">
        <defs>
            <pattern id="talks-grid" width="64" height="64" patternUnits="userSpaceOnUse">
                <path d="M 64 0 L 0 0 0 64" fill="none" stroke="white" stroke-width="2" />
            </pattern>
        </defs>
        <rect width="100%" height="100%" fill="url(#talks-grid)" />
    </svg>

    <div class="relative z-10 mx-auto flex max-w-[1000px] flex-col gap-6 px-8 py-16 md:px-10 md:py-24">
        <h1 class="max-w-[900px] text-4xl font-extrabold leading-[1.05] tracking-tight md:text-[60px]">
            Undergraduate Mathematics Weekly Talks
        </h1>

        <p class="max-w-2xl text-lg leading-relaxed text-white/70">
            Thirty to forty-five minutes of mathematics, every week of term presented to primarily undergraduate audiences. We are looking for speakers now.
        </p>

        <div class="mt-2 flex flex-wrap items-center gap-4">
            <a
                href={APPLY_URL}
                target="_blank"
                rel="noreferrer noopener"
                class="inline-flex items-center gap-2 bg-white px-6 py-3 font-mono text-sm font-bold uppercase tracking-[0.1em] text-black transition-colors hover:bg-[#a893ff]"
            >
                Apply to speak
                <ArrowUpRight size={16} weight="bold" />
            </a>
        </div>
    </div>
</div>

<div class="mx-auto flex max-w-[1000px] flex-col gap-4 px-8 py-12 md:px-10 md:py-16">
    <div class="max-w-3xl">
        {@html data.html}
    </div>

    <div class="mt-10 flex w-full max-w-3xl flex-col items-start justify-between gap-4 border-t border-black/10 pt-8 sm:flex-row sm:items-center">
        <p class="font-mono text-sm uppercase tracking-[0.12em] text-[#2b2b2b]">
            Speaker applications — Term 1 2027
        </p>
        <a
            href={APPLY_URL}
            target="_blank"
            rel="noreferrer noopener"
            class="inline-flex shrink-0 items-center gap-2 bg-[#141414] px-5 py-3 font-mono text-sm font-bold uppercase tracking-[0.1em] text-white transition-colors hover:bg-[#7862e2]"
        >
            Open application form
            <ArrowUpRight size={16} weight="bold" />
        </a>
    </div>
</div>
